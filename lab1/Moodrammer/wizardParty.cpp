#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>


bool checkAllVisitedOnce(vi &visitingTimes) {
    for(auto house : visitingTimes) {
        if(house != 1)
            return 0;
    }
    return 1;
}

void detectCycle(int currHouse, vi &visitingTimes, vvi &edges, bool &ans) {
    if(visitingTimes[currHouse] == 2 && currHouse != 0) return;
    
    if(currHouse == 0 && visitingTimes[currHouse] == 2) {
        visitingTimes[0] = 1;
        if(checkAllVisitedOnce(visitingTimes)) {
            ans = 1;
        }
        visitingTimes[0] = 2; 
        return;
    }

    vi currPortals = edges[currHouse];
    for(auto house : currPortals) {
        visitingTimes[house]++;
        detectCycle(house, visitingTimes, edges, ans);
        visitingTimes[house]--;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vvi portals(n);
    int h1, h2;

    if(n == 1) return cout << 1 << endl, 0;

    for(int i = 0; i < e; i++) {
        cin >> h1 >> h2;
        portals[h1].push_back(h2);
        portals[h2].push_back(h1);
    }

    bool ans = 0;
    vi visitingTimes(n, 0);
    visitingTimes[0] = 1;
    detectCycle(0, visitingTimes, portals, ans);
    cout << ans << endl;
    return 0;
}
