#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>
#include <climits>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using vec = vector<int>;
using vit = vector<int>::iterator;

#define DEFINE_SORT(algorithm) namespace algorithm { void sort(vec &data); }

namespace Sorting {
  void run(void (*algorithm)(vec&), const string &dataPath, const string &sortedPath, const string &timePath);

  DEFINE_SORT(Selection);
  DEFINE_SORT(Insertion);
  DEFINE_SORT(Merge);
  DEFINE_SORT(Quick);
  DEFINE_SORT(Hybrid);

  void (*use[])(vec&) = { Selection::sort, Insertion::sort, Merge::sort, Quick::sort, Hybrid::sort };
}

int main(int argc, char const *argv[])
{
  if (argc < 5) return 0xFF;

  int algorithm = std::stoi(argv[1]);
  if (algorithm >= 0 && algorithm <= 4)
    Sorting::run(Sorting::use[algorithm], argv[2], argv[3], argv[4]);
   
  return 0;
}

// ===========================================================================================================
namespace Sorting {
  void read_data(const string &dataPath, vec &data) {
    ifstream inData(dataPath);
    for (string line; std::getline(inData, line);) {
      int x = std::stoi(line);
      data.push_back(x);
    }
  }

  void write_data(const string &sortedPath, const string &timePath, const vec &sorted, double time) {
    ofstream outSorted(sortedPath);
    ofstream outTime(timePath);
    for (auto &x: sorted) {
      outSorted << x << std::endl;
    }

    outTime << time; 
  }

  void run(void (*algorithm)(vec&), const string &dataPath, const string &sortedPath, const string &timePath) {
    using namespace std::chrono;
    vec data;
    read_data(dataPath, data);

    auto start = high_resolution_clock::now();
    algorithm(data);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end-start);
    write_data(sortedPath, timePath, data, (double)duration.count()/1000);
  }

// ===========================================================================================================
  namespace Selection {
    void iterate(const vit start, const vit end) {
      for (vit it = start; it != end; it++) {
        vit min = it;
        for (vit jt = it+1; jt != end; jt++) {
          min = *( jt ) < *( min ) ? jt : min;
        }

        std::swap(*( it ), *( min ));
      }
    }

    void sort(vec &data) {
      iterate(data.begin(), data.end());
    }
  }

  // ===========================================================================================================
  namespace Insertion {
    void iterate(const vit start, const vit end) {
      for (vit it = start+1; it != end; it++) {
        int inserted = *( it );
        vit jt = it - 1;
        while (inserted < *( jt )) {
          *( jt + 1 ) = *( jt );
          if (jt == start) break;
          jt--;
        }
        *( jt ) = inserted;
      }
    }
    void sort(vec &data) {
      iterate(data.begin(), data.end());
    }
  }

// ===========================================================================================================
  namespace Merge {
    void merge(const vit start, const vit mid, const vit end) {
      vec left(start, mid);
      left.push_back(INT_MAX);
      vec right(mid, end);
      right.push_back(INT_MAX);

      vit l = left.begin();
      vit r = right.begin();
      vit m = start;

      while (m != end) {
        if (*l < *r)  *(m++) = *(l++);
        else          *(m++) = *(r++);
      }
    }

    void recursive_merge(const vit start, const vit end) {
      int dist = std::distance(start, end);
      if (dist == 1) return; // Vector contains one element

      vit mid = start + (dist/2);
      recursive_merge(start, mid);
      recursive_merge(mid, end);

      merge(start, mid, end);
    }

    void sort(vec &data) {
      recursive_merge(data.begin(), data.end());
    }
  }

// ===========================================================================================================
  namespace Quick {
    vit partition(const vit start, const vit end) {
      int pivot = *start;
      vit p = start;
      vit lower = start+1;
      
      for (vit curr = lower; curr != end; curr++) {
        if (*curr < pivot) {
          std::swap(*curr, *lower);
          p++, lower++;
        }
      }
      std::swap(*start, *p);
      return p;
    }

    void recursive_partition(const vit start, const vit end) {
      int dist = std::distance(start, end);
      if (dist <= 1) return; // Vector contains one element

      vit randomPivot = start + std::rand() % dist;
      std::swap(*start, *randomPivot);
      vit p = partition(start, end);

      recursive_partition(start, p);
      recursive_partition(p+1, end);
    }

    void sort(vec &data) {
      std::srand(time(NULL));
      recursive_partition(data.begin(), data.end());
    }
  }

// ===========================================================================================================
  namespace Hybrid {
    const int SWAPPING_THRESHOLD = 50;
    void recursive_partition(const vit start, const vit end) {
      int dist = std::distance(start, end);
      if (dist < 1) return;
      if (dist <= SWAPPING_THRESHOLD) return Insertion::iterate(start, end);

      vit randomPivot = start + std::rand() % dist;
      std::swap(*start, *randomPivot);
      vit p = Quick::partition(start, end);

      recursive_partition(start, p);
      recursive_partition(p+1, end);
    }

    void sort(vec &data) {
      std::srand(time(NULL));
      recursive_partition(data.begin(), data.end());
    };
  }
}
