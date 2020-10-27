#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <cstring>                    
#include <sstream>
#include <numeric>
#include <assert.h>

using namespace std;

#define ll long long

ll const N = 1e5 + 10;
ll const INF = 1e18;
ll const mod = 1000000009;

///////////////////////////////////////////////////////////////////

int n, m, adj[8][8], done[8], best=8;

void solve(int idx = 0, int cnt=0){
    
    if(idx == n){
        best = min(best, cnt);
        return;
    }
    if(done[idx]) { 
        solve(idx+1, cnt);
        return;
    }

    int L = (1 << idx), R = (1 << n) - 1;

    for(int i=L; i<=R; i+=L*2){
        vector<int> bits;
    
        int tmp = i, b=0, ok=1;
        while(tmp){
            if(tmp & 1) bits.push_back(b);
            b++, tmp >>= 1;
        }

        for(int x : bits) if(done[x]){ok=0; break;}
        for(int x : bits)for(int y : bits){ if(adj[x][y])ok=0; }
        
        if(!ok)continue;

        for(int x : bits)done[x] = 1;
        solve(idx + 1, cnt+1);
        for(int x : bits)done[x] = 0;
    }

    return;
}

int main(){

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    solve();
    cout << best;

return 0;}