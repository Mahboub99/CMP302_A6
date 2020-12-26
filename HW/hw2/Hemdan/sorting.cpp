// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
#include <stdlib.h>

#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

void insertionSplit(vector<int> &a, int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int key = a[i];
    int j = i - 1;

    while (j >= l && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void insertionSort(vector<int> &a) {
  int l = 0;
  int r = a.size() - 1;
  insertionSplit(a, l, r);
}

void selectionSplit(vector<int> &a, int l, int r) {
  for (int i = l; i < r; i++) {
    int curMin = i;
    for (int j = i + 1; j < r; j++) {
      if (a[curMin] > a[j]) { // we got a new minimum
        curMin = j;
      }
    }
    swap(a[i], a[curMin]);
  }
}

void selectionSort(vector<int> &a) {
  int l = 0;
  int r = a.size();
  selectionSplit(a, l, r);
}

void merge(vector<int> &a, const int l, const int mid, const int r) {
  const int lftSize = mid - l + 1;
  const int rgtSize = r - mid;

  // we added extra element space with OO to prevent extra check if sizes
  vector<int> lft(lftSize + 1);
  vector<int> rgt(rgtSize + 1);

  // configurable based on maximum element in our a
  const int OO = INT_MAX;

  lft[lftSize] = OO;
  rgt[rgtSize] = OO;

  // filling the two parts
  for (size_t i = 0; i < lftSize; i++) {
    lft[i] = a[l + i];
  }

  for (size_t i = 0; i < rgtSize; i++) {
    rgt[i] = a[mid + i + 1];
  }

  unsigned int lftIter = 0;
  unsigned int rgtIter = 0;

  for (size_t i = l; i <= r; i++) {
    if (lft[lftIter] <= rgt[rgtIter]) {
      a[i] = lft[lftIter++];
    } else {
      a[i] = rgt[rgtIter++];
    }
  }
}

void mergeSplit(vector<int> &a, const unsigned int l, const unsigned int r) {
  if (l < r) {
    const int mid = l + (r - l) / 2;

    mergeSplit(a, l, mid);
    mergeSplit(a, mid + 1, r);

    merge(a, l, mid, r);
  }
}

void mergeSort(vector<int> &a) {
  const int l = 0;
  const int r = a.size() - 1;

  mergeSplit(a, l, r);
}

int partition(vector<int> &a, int l, int r) {
  const int pivot = a[r];

  int curMin = l - 1;
  for (size_t i = l; i <= r - 1; i++) {
    if (a[i] < pivot) { // we got a new minimum
      curMin++;
      swap(a[i], a[curMin]);
    }
  }

  swap(a[++curMin], a[r]); // place pivot in its right position
  return curMin;
}

void quickSplit(vector<int> &a, int l, int r) {
  if (l < r) {
    int q = partition(a, l, r);
    quickSplit(a, l, q - 1);
    quickSplit(a, q + 1, r);
  }
}

void quickSort(vector<int> &a) {
  const int l = 0;
  const int r = a.size() - 1;
  quickSplit(a, l, r);
}


void hybridSplit(vector<int> &a, const int l, const int r, const int threshold) {
  if (l < r) {
    if (r - l < threshold) {
      insertionSplit(a, l, r);
      return;
    } else {
      const int q = partition(a, l, r);
      hybridSplit(a, l, q - 1, threshold);
      hybridSplit(a, q + 1, r, threshold);
    }
  }
}

void hybridSort(vector<int> &a) {
  const int l = 0;
  const int r = a.size() - 1;
  const int threshold = 20;
  hybridSplit(a, l, r, threshold);
}

double calculateTimeConsumed(time_t start, time_t end) {
  return double(end - start) / CLOCKS_PER_SEC;
}


string getScript(int n, string inputFile){
  return "python runscript.py " + to_string(n) + " " + inputFile;
}


int main(int argc, char *argv[]) {
  IO;
  int type = argv[1][0] - '0';
  string inputFile = argv[2];
  string outputFile = argv[3];
  string runningTime = argv[4];

  int n = 10000, x;
  vector<int> a;

  string script = getScript(n, inputFile);
  system(&script[0]);

  ifstream in(inputFile);
  ofstream out(outputFile);
  ofstream outT(runningTime);

  while(in >> x) {
    a.push_back(x);
  }

  srand(time(NULL));
  time_t timeStart, timeEnd;

  switch (type){
    case 0: // Selection
      timeStart = clock();
      selectionSort(a);
      timeEnd = clock();
      break;
    case 1: // Insertion
      timeStart = clock();
      insertionSort(a);
      timeEnd = clock();
      break;
    case 2: // Merge
      timeStart = clock();
      mergeSort(a);
      timeEnd = clock();
      break;
    case 3: // Quick
      timeStart = clock();
      quickSort(a);
      timeEnd = clock();
      break;
    case 4: // Hybrid
      timeStart = clock();
      hybridSort(a);
      timeEnd = clock();
      break;
    default: // Other
      timeStart = clock();
      hybridSort(a);
      timeEnd = clock();
      break;
  }
  
  double consumedTime = calculateTimeConsumed(timeStart, timeEnd);
  outT << consumedTime << endl;

  for(int& i : a) {
    out << i << ' ';
  }
  out << endl;
}
