#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Each bit in factor corresponds to whether or not
 * a member is included in the team
 */
int eval(int factor, int numOfVertices, const vector<vector<bool>> &synergies) {
  int tmp = factor;
  int ones = 0; // Number of ones in factor == number of members in the team
  while (tmp) {
    ones += (tmp & 1);
    tmp >>= 1;
  }

  // Fill the proposed team
  vector<int> team;
  for (int i = 0; i < numOfVertices; i++) {
    if ((factor >> i) & 1) team.push_back(i);
  }

  // Validate the team's synergy
  for (int i = 0; i < team.size(); i++) {
    for (int j = i+1; j < team.size(); j++) {
      if (!synergies[team[i]][team[j]]) return -1;
    }
  }

  return ones;
}

int main() {
  int N; cin >> N;
  int E; cin >> E;
  vector<vector<bool>> synergies(N, vector<bool>(N, false));
  for (int i = 0; i < E; i++) {
    int m1, m2;
    cin >> m1 >> m2;
    synergies[m1][m2] = synergies[m2][m1] = true;
  }

  // Try all possible combinations
  int maxSynergy = -1;
  for (int f = 0; f < (1 << N); f++) {
    int e = eval(f, N, synergies);
    maxSynergy = e > maxSynergy ? e : maxSynergy;
  }

  cout << maxSynergy;
  return 0;
}

