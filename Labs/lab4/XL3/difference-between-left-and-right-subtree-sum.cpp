#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using vec = vector<int>;
using vii = vector<pair<int, int>>;
using s64 = long long;

/**
 * Traverse the tree recursively,
 * each node that satisfies the condition, increments the answer.
 *
 * Sum(subtree) = subtree.value + Sum(subtree.left) + Sum(subtree.right)
 */
int solve(vec &elements, vii &children, const s64 MAX_DIFFERENCE) {
  int answer = 0;
  std::function<s64(int)> evaluate_subtree = [&](int index) -> s64 {
    s64 leftSum = 0;
    if (children[index].first > 0)
      leftSum = evaluate_subtree(children[index].first);

    s64 rightSum = 0;
    if (children[index].second > 0)
      rightSum = evaluate_subtree(children[index].second);

    if (abs(leftSum - rightSum) <= MAX_DIFFERENCE) answer++;
    return elements[index] + leftSum + rightSum;
  };

  evaluate_subtree(0);
  return answer;
}

int main() {
  int N; s64 R;
  cin >> N >> R;
  vec input(N);
  for (auto &x : input) cin >> x;

  int E; cin >> E;

  /**
   * Instead of implementing a tree data structure,
   * keeping only the edges will suffice.
   *
   * Vector of (index of left child, index of right child)
   * Each index references an index in the input tree.
   */
  vii children(N, {-1, -1});

  char LorR; int p, ch;
  for (int e = 0; e < E; e++) {
    cin >> LorR >> p >> ch;

    if (LorR == 'L') children[p].first = ch;
    else             children[p].second = ch;
  }

  int answer = solve(input, children, R);
  cout << answer;
  return 0;
}
