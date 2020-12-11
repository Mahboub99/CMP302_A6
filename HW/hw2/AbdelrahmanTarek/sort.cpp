#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <sys/resource.h>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::swap;
using std::vector;

namespace sorting
{
  typedef void (*sortFunction)(vector<int> &vec, int l, int r);

  void selectionSort(vector<int> &vec, int l, int r)
  {
    for (int i = l; i < r; i++)
    {
      int minIdx = i;
      for (int j = i + 1; j < r; j++)
      {
        if (vec[j] < vec[minIdx])
          minIdx = j;
      }

      swap(vec[i], vec[minIdx]);
    }
  }

  void insertionSort(vector<int> &vec, int l, int r)
  {
    for (int i = l + 1; i < r; i++)
    {
      int mn = vec[i];
      int j = i - 1;
      while (j >= l && vec[j] > mn)
      {
        vec[j + 1] = vec[j];
        j--;
      }
      vec[j + 1] = mn;
    }
  }

  void merge(vector<int> &vec, int l, int r, int mid)
  {
    vector<int> lvec(vec.begin() + l, vec.begin() + mid);
    vector<int> rvec(vec.begin() + mid, vec.begin() + r);

    int i = 0, j = 0, k = l;

    while (i < lvec.size() && j < rvec.size())
    {
      if (lvec[i] < rvec[j])
        vec[k++] = lvec[i++];
      else
        vec[k++] = rvec[j++];
    }

    while (i < lvec.size())
      vec[k++] = lvec[i++];
    while (j < rvec.size())
      vec[k++] = rvec[j++];
  }

  void mergeSort(vector<int> &vec, int l, int r)
  {
    if (r - l > 1)
    {
      int mid = l + (r - l) / 2;

      mergeSort(vec, l, mid);
      mergeSort(vec, mid, r);

      merge(vec, l, r, mid);
    }
  }

  int partition(vector<int> &vec, int l, int r)
  {
    int pivot = vec[r - 1];
    int i = (l - 1);

    for (int j = l; j < r; j++)
    {
      if (vec[j] < pivot)
      {
        i++;
        swap(vec[i], vec[j]);
      }
    }
    swap(vec[i + 1], vec[r - 1]);

    return i + 1;
  }

  void quickSort(vector<int> &vec, int l, int r)
  {
    if (r - l > 1)
    {
      int pivot = partition(vec, l, r);

      quickSort(vec, l, pivot);
      quickSort(vec, pivot + 1, r);
    }
  }

  void hybridSort(vector<int> &vec, int l, int r)
  {
    if (r - l <= 50)
    {
      insertionSort(vec, l, r);
      return;
    }

    if (r - l > 1)
    {
      int mid = l + (r - l) / 2;

      hybridSort(vec, l, mid);
      hybridSort(vec, mid, r);

      merge(vec, l, r, mid);
    }
  }

  sortFunction sortFunctions[] = {
      selectionSort,
      insertionSort,
      mergeSort,
      quickSort,
      hybridSort,
  };

} // namespace sorting

void run(int sel, char *in, char *out, char *runTime)
{
  ifstream file(in);

  if (!file || !file.is_open())
  {
    throw std::ios::failure("Error opening file!");
  }

  int num;
  vector<int> vec;

  while (file >> num)
  {
    vec.push_back(num);
  }

  file.close();

  int n = vec.size();
  // sort
  int l = 0, r = n;

  auto start = std::chrono::steady_clock::now();
  sorting::sortFunctions[sel](vec, l, r);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;

  ofstream outputFile(out);

  if (!outputFile || !outputFile.is_open())
  {
    throw std::ios::failure("Error opening outputFile!");
  }

  for (auto x : vec)
  {
    outputFile << x << '\n';
  }

  outputFile.close();

  ofstream runTimeFile(runTime);

  if (!runTimeFile || !runTimeFile.is_open())
  {
    throw std::ios::failure("Error opening runTimeFile!");
  }

  runTimeFile << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;

  runTimeFile.close();
}

int main(int argc, char **argv)
{
  if (argc != 5)
  {
    cout << "Wrong aguments\n";
    return 1;
  }

  const rlim_t kStackSize = 32 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }

  try
  {
    run(std::atoi(argv[1]), argv[2], argv[3], argv[4]);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
