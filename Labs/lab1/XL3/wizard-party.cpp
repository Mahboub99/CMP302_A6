#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Traverse the graph recursively
 * until all houses are crossed
 * and the final house is connected to the starting house
 */
bool take_path(int house, int nHouses, set<int> crossed, const vector<set<int>> &linked) {
  if (crossed.size() == nHouses) {
    return linked[house].find(0) != linked[house].end();
  }

  bool answer = false;
  for (auto& candidateHouse: linked[house]) {
    if (crossed.find(candidateHouse) != crossed.end()) continue; // Skip if crossed

    set<int> candidateCrossed(crossed);
    candidateCrossed.insert(candidateHouse);
    answer |= take_path(candidateHouse, nHouses, candidateCrossed, linked);
  }
  return answer;
}


int main() {
  int N; cin >> N;
  int E; cin >> E;
  // Each house has a set of houses which are connected to it
  vector<set<int>> linked(N);

  for (int i = 0; i < E; i++) {
    int h1, h2;
    cin >> h1 >> h2;

    linked[h1].insert(h2);
    linked[h2].insert(h1);
  }
  linked[0].insert(0); // The first house can reach itself, useful for when the graph only has one house

  set<int> crossed;
  crossed.insert(0); // Start by crossing the first house
  cout << (take_path(0, N, crossed, linked) ? 1 : 0);

  return 0;
}

