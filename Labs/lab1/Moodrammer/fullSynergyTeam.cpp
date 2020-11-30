#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

#define vs vector<set<int>> 
#define vb vector<bool>

bool isfullSynergyApplied(vb &inTeam, vs &edges, int &numPlayers, int &teamSize) {
    int cnt = 0;
    bool good = true;
    for(int pl1 = 0; pl1 < numPlayers; pl1++) {
        good = true;
        if(inTeam[pl1]) {
            teamSize++;
            int pl2 = pl1 + 1;
            for(; pl2 < numPlayers; pl2++) {
                if(inTeam[pl2]) {
                        if(edges[pl1].find(pl2) == edges[pl1].end()) {
                            good = false; 
                            break;
                        }
                    }
            }
            cnt += (good);
        }
    }
    
    return (cnt == teamSize);
}

void findMaxTeamSize(int currPlayer, int &numPlayers, int &maxTeamSize, vs &edges, vb &inTeam) {
    if(currPlayer == numPlayers) {
        int teamSize = 0;
        if(isfullSynergyApplied(inTeam, edges, numPlayers, teamSize)) {
            if(teamSize > maxTeamSize) 
                maxTeamSize = teamSize;
        }
        return;
    }

    inTeam[currPlayer] = 1;
    findMaxTeamSize(currPlayer + 1, numPlayers, maxTeamSize, edges, inTeam);
    inTeam[currPlayer] = 0;
    findMaxTeamSize(currPlayer + 1, numPlayers, maxTeamSize, edges, inTeam);
}


int main() {
    int v, e;
    cin >> v >> e;
    vs edges(v);
    int p1, p2;

    if(e == 0) return cout << 1 << endl, 0;

    while(e--) {
        cin >> p1 >> p2;
        edges[p1].insert(p2);
        edges[p2].insert(p1);
    }

    int maxTeamSize = INT32_MIN; 
    vb inTeam(v, 0);

    findMaxTeamSize(0, v, maxTeamSize, edges, inTeam);
    cout << maxTeamSize << endl;
}
