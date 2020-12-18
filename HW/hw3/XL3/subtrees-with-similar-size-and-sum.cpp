#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

using u64 = unsigned long long;
using pss = std::pair<int, u64>;
using vec = std::vector<int>;
using vii = std::vector<std::pair<int, int>>;
using mss = std::unordered_map<int, std::unordered_map<u64, int>>;
using std::cin;
using std::cout;

/**
 * Here we just need to record all the (sum, size) pairs that
 * we have reached while constructing the tree.
 *
 * If any (size, sum) pair has been achieved more than once,
 * the test case satisfies the conditions.
 */
int solve(vec &elements, vii &children, const int SUBTREE_SIZE) {
  // Construct tree
  // solution[size][sum] contains the count of subtrees that satisfy the condition
  mss solution;
  std::function<pss(int, int)> evaluate_subtree = [&](int value, int childrenIdx) -> pss {
    int l = children[childrenIdx].first;
    int r = children[childrenIdx].second;
    pss sizeSum { 1, value };

    if (l > 0) {
      auto leftSizeSum = evaluate_subtree(elements[l], l);
      sizeSum.first += leftSizeSum.first;
      sizeSum.second += leftSizeSum.second;
    }

    if (r > 0) {
      auto rightSizeSum = evaluate_subtree(elements[r], r);
      sizeSum.first += rightSizeSum.first;
      sizeSum.second += rightSizeSum.second;
    }

    solution[sizeSum.first][sizeSum.second]++;
    return sizeSum;
  };

  evaluate_subtree(elements[0], 0);

  for (auto &sm: solution) if (sm.first > SUBTREE_SIZE)  // Size
      for (auto &sc: sm.second) if (sc.second > 1) return 1; // Count

  return 0;
}

int main() {
  int N, M;;
  cin >> N >> M;

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

  cout << solve(input, children, M);
  return 0;
}
