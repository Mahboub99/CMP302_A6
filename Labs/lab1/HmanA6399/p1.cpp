#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool>* synergy;
int n = -1, synCount, s1, s2, maxTeam = 0;

void printSynergy() {
    if (n != -1)
        for (int i = 0; i < n; ++i) {
             for (int j = 0; j < n; ++j)
                 cout << synergy[i][j] << ' ';
            cout << '\n';
        }
}

vector<int> onesIdxsOfMask(int mask) {
    vector<int> ones;
    for (int i = 0; (1 << i) <= mask; ++i) {
        if (mask & (1 << i))
            ones.push_back(i);
    }
    return ones;
}

bool fullSyn(vector<int> members) {
    int sz = members.size();
    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            if (!synergy[members[i]][members[j]])
                return false;
    return true;
}

int getTeamSizeIfFullSyn(int mask) {
    vector<int> members = onesIdxsOfMask(mask);
    if (fullSyn(members))
        return members.size();
    return 0;
}

int main() {
    cin >> n;
    
    // Init the synergy array
    synergy = new vector<bool>[n];
    for (int i = 0; i < n; ++i)
        synergy[i].assign(n, 0);
    
    // Fill synergy array
    cin >> synCount;
    for (int i = 0; i < n; ++i)
        synergy[i][i] = true;
    for (int i = 0; i < synCount; ++i) {
        cin >> s1 >> s2;
        synergy[s1][s2] = synergy[s2][s1] = true;
    }

    int mask = (1 << n);
    while (--mask) {
        maxTeam = max(getTeamSizeIfFullSyn(mask), maxTeam);
    }

    cout << maxTeam << '\n';
    return 0;
}
