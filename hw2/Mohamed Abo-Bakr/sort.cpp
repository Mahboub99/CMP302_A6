#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

void Selection(vector<int> &arr);
void Insertion(vector<int> &arr);
vector<int> MergeSort(vector<int> &arr, int l, int r);
void Quick(vector<int> &arr, int l, int r);
void hybrid(vector<int> &arr);

int main(int argc, char *argv[])
{
  // validating command line argument
  if (argc != 5)
  {
    cout << "Usage: ./sorting.exe algo_num inFile outFile outTimeFile";
    return 1;
  }

  // reading input
  fstream inFile(argv[2], fstream::in);
  if (!inFile.is_open())
  {
    cout << "The file was not opened!";
    return 1;
  }

  vector<int> list;
  string s;
  while (getline(inFile, s))
  {
    list.push_back(stoi(s));
  }
  inFile.close();

  int algo = atoi(argv[1]);

  uint64_t ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

  switch (algo)
  {
  case 0:
    Selection(list);
    break;
  case 1:
    Insertion(list);
    break;
  case 2:
    list = MergeSort(list, 0, list.size());
    break;
  case 3:
    Quick(list, 0, list.size() - 1);
    break;
  case 4:
    hybrid(list);
    break;
  default:
    break;
  }

  uint64_t dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - ms;
  fstream outFile(argv[3], fstream::out), timeFile(argv[4], fstream::out);
  timeFile << "Time: " << dur << " ms";
  timeFile.close();

  for (auto i : list)
  {
    outFile << i << endl;
  }
  outFile.close();
}

void Selection(vector<int> &arr)
{
  int minI;
  for (int i = 0, n = arr.size(); i < n; i++)
  {
    minI = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[minI])
      {
        minI = j;
      }
    }
    swap(arr[i], arr[minI]);
  }
}

void Insertion(vector<int> &arr)
{
  int temp, index;
  for (int i = 1, n = arr.size(); i < n; i++)
  {
    temp = arr[i];
    index = i;
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] > temp)
      {
        arr[j + 1] = arr[j];
        index = j;
      }
      else
      {
        break;
      }
    }
    arr[index] = temp;
  }
}

vector<int> Merge(vector<int> &left, vector<int> &right)
{
  vector<int> merged(left.size() + right.size() + 2);
  left.push_back(INT32_MAX);
  right.push_back(INT32_MAX);
  int j = 0, k = 0;
  for (int i = 0, n = merged.size(); i < n; i++)
    merged[i] = (left[j] > right[k]) ? right[k++] : left[j++];
  merged.pop_back();
  merged.pop_back();
  return merged;
}

vector<int> MergeSort(vector<int> &arr, int l, int r)
{
  if (r - l < 2)
  {
    vector<int> v;
    v.push_back(arr[l]);
    return v;
  }
  int mid = (r + l) / 2;
  vector<int> left, right;
  left = MergeSort(arr, l, mid);
  right = MergeSort(arr, mid, r);
  return Merge(left, right);
}

int part(vector<int> &arr, int p, int r)
{
  int x = arr[r], i = p - 1, temp;

  for (int j = p; j < r; j++)
  {
    if (arr[j] <= x)
    {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return i + 1;
}

void Quick(vector<int> &arr, int p, int r)
{
  if (p < r)
  {

    int q = part(arr, p, r);
    Quick(arr, p, q - 1);
    Quick(arr, q + 1, r);
  }
}

void hybrid(vector<int> &arr)
{
  int n = arr.size(), conv = 0;
  for (int i = 0; i < n - 1; i++)
    conv = (arr[i + 1] >= arr[i]) ? conv + 1 : conv - 1;

  if (conv > n/2)
  {
    Insertion(arr);
  }
  else if (conv < - n / 2)
  {
    int temp;
    for (int i = 0; i <= n / 2; i ++)
    {
      temp = arr[i];
      arr[i] = arr[n-1 - i];
      arr[n-1-i] = temp;
    }
    Insertion(arr);
  }
  else 
  {
    Quick(arr, 0, n - 1);
  }
}