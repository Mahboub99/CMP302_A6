#include <iostream>
#include <vector>
#include <functional>
#include <set>

using namespace std;
using vec = vector<int>;
using vii = vector<pair<int, int>>;

/**
 * Returns the median of a multiset
 * i.e. the middle element in the set
 */
int median(multiset<int> &st) {
  if (st.empty()) return -1;
  auto it = st.begin();
  std::advance(it, st.size() / 2);
  return *it;
}

/**
 * Traverse the tree recursively,
 * each node that matches the condition, increments the answer.
 *
 * Store all the nodes in the path from the root to the node currently being processed.
 * We use a multiset here because it's sorted by default, which makes finding the median
 * element trivial.
 *
 * Remove the current node after processing is done, to move up the tree
 */
int solve(vec &elements, vii &children) {
  int answer = 0;
  multiset<int> currentPath;
  std::function<void(int, bool)> evaluate_subtree = [&](int index, bool valid) {
    currentPath.insert(elements[index]);

    if (children[index].first > 0)
      evaluate_subtree(children[index].first, !valid);

    if (children[index].first > 0)
      evaluate_subtree(children[index].second, !valid);

    if (valid && elements[index] == median(currentPath))
      answer++;

    currentPath.erase(currentPath.lower_bound(elements[index]));
  };

  evaluate_subtree(0, true);
  return answer;
}

int main() {
  int N; cin >> N;
  vec input(N);
  for (auto &x : input) cin >> x;

  int E; cin >> E;
  vii children(N, {-1, -1});

  char LorR; int p, ch;
  for (int e = 0; e < E; e++) {
    cin >> LorR >> p >> ch;

    if (LorR == 'L') children[p].first = ch;
    else             children[p].second = ch;
  }

  cout << solve(input, children);
  return 0;
}
