#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <climits>

using vec = std::vector<int>;
using vii = std::vector<std::pair<int, int>>;
using u64 = unsigned long long;
using std::cin;
using std::cout;

/**
 * Here we only need to assign elements to their levels
 * After we've extracted level data from the tree,
 * the solution is simple.
 */
u64 solve(vec &elements, vii &children) {
  // Construct level data: (min_element, sum)
  std::vector<std::pair<int, u64>>levels(elements.size()+10, { INT_MAX, 0 });
  levels[0] = { elements[0], elements[0] };

  std::function<int(int, int)> fill_levels = [&](int level, int childIdx) -> int {
    int l = children[childIdx].first;
    int lHeight = 1;
    int r = children[childIdx].second;
    int rHeight = 1;

    if (l > 0) {
      levels[level+1].first = std::min(levels[level+1].first, elements[l]);
      levels[level+1].second += elements[l];
      lHeight += fill_levels(level + 1, l);
    }

    if (r > 0) {
      levels[level+1].first = std::min(levels[level+1].first, elements[r]);
      levels[level+1].second += elements[r];
      rHeight += fill_levels(level + 1, r);
    }

    return std::max(lHeight, rHeight);
  };

  // Calculate K
  int treeHeight = fill_levels(0, 0);
  int L = elements[0] % treeHeight;
  int K = (levels[L].first % treeHeight) ? levels[L].first % treeHeight : 1;

  for (L = 0; L < treeHeight; L += K) {
    cout << levels[L].second;
  }
}

int main() {
  int N; cin >> N;

  vec input(N);
  for (auto &x : input) cin >> x;

  int E; cin >> E;
  vii children(N, {-1, -1});
  for (int e = 0; e < E; e++) {
    char LorR; int p, ch;
    cin >> LorR >> p >> ch;

    if (LorR == 'L') children[p].first = ch;
    else             children[p].second = ch;
  }

  solve(input, children);
  return 0;
}
