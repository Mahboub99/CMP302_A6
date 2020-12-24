#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <climits>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

/**
 * The optimal solution
 * S(row, col) = Value(row, col) + max( S(other row, previous col),
 *                                      S(same row, previous col) <excluding the item>)
 *
 * Build the memo vector in a bottom-up fashion
 */
int solve(vector<int> input, const int N) {
  if (N == 0) return N;
  if (N == 1) return std::max(input[0], input[1]);

  // Contains the optimal solution, regardless of choice
  vector<int> sum(2*N, -1);
  sum[0] = input[0]; 
  sum[N] = input[N];

  int skip, take;
  int cell, opposite;
  for (int col = 1; col < N; col++) {
    for (int row = 0; row < 2; row++) {
      cell = N*row + col;
      opposite = N*(1-row) + col;

      take = sum[opposite-1];
      skip = sum[cell-1] - input[cell-1];

      sum[cell] = input[cell] + std::max(take, skip);
    }
  }
  return std::max(sum[N-1], sum[2*N-1]);
}

int main() {
  int N; cin >> N;

  vector<int> input(2*N);
  for (auto &x: input) cin >> x;

  cout << solve(input, N);
  return 0;
}

int solve_td(vector<int> input, const int N) {
  if (!N) return N;
  vector<int> sum(2*N, -1);
  sum[N-1] = input[N-1];
  sum[2*N-1] = input[2*N-1];

  std::function<int(int)> get_sum = [&](int cell) -> int {
    // If the cell has not been visited
    if (sum[cell] < 0) {
      int skip = get_sum(cell+1);

      int take = input[cell];
      int opposite = cell/N ? cell-N : cell+N;
      take += get_sum(opposite+1);

      sum[cell] = std::max(take, skip);
    }
    return sum[cell];
  };

  return std::max(get_sum(0), get_sum(N));
}
