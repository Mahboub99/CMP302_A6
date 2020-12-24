#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>

using std::cin;
using std::vector;
using std::set;

/**
 * This follows the coin change problem where the optimal solution
 * shots(hp) = 1 + shots(hp - optimalWeapon)
 *
 * The remaining health would be 
 * health(hp) = health(hp - optimalWeapon)
 *
 * Build the memo vectors in a bottom-up fashion
 */
void solve(vector<int> monsters, set<int> firepower) {
  const int MAX_HP = *std::max_element(monsters.begin(), monsters.end());
  const int MIN_X = *firepower.begin();

  // This initializes the health vector to the values { 0, 1, 2, 3, 4, ... }
  vector<int> health(MAX_HP + 1);
  std::iota(health.begin(), health.end(), 0);

  // Any health value below the minimum weapon takes 0 shots to kill
  vector<int> shots(MAX_HP + 1, -1);
  std::fill_n(shots.begin(), MIN_X, 0);

  // At every health level which exactly equals a weapon
  // the remaining health is 0, and only one shot is needed to kill
  for (auto x : firepower) {
    health[x] = 0;
    shots[x] = 1;
  }
  shots[0] = 0;

  int minHealth, minShots;
  for (int hp = MIN_X + 1; hp <= MAX_HP; hp++) {
    if (shots[hp] >= 0) continue;

    // Find the minimum reachable health
    minHealth = minShots = INT_MAX;
    for (auto it = firepower.begin(); it != firepower.upper_bound(hp); it++) {
      minHealth = std::min(minHealth, health[hp - *it]);
    }

    // Find the minimum shots needed to reach said health
    for (auto it = firepower.begin(); it != firepower.upper_bound(hp); it++) {
      if (health[hp - *it] == minHealth) {
        minShots = std::min(minShots, shots[hp - *it]);
      }
    }

    shots[hp] = 1 + minShots;
    health[hp] = minHealth;
  }

  for (auto monster : monsters) {
    std::printf("%d %d\n", health[monster], shots[monster]);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> monsters(N);
  for (auto &x : monsters) cin >> x;

  int M, x;
  cin >> M;
  set<int> firepower;
  while (M--) {
    cin >> x;
    firepower.insert(x);
  }

  solve(monsters, firepower);
  return 0;
}
