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
#define lop(i,n) for(int i=0; i<n; i++)

ll const N = 2e1 + 10;
ll const INF = 1e18;
ll const mod = 1000000009;

///////////////////////////////////////////////////////////////////

int n, m, vis[N], ok = 0;
vector<int> e[N];

void solve(int idx){
    vis[idx] = 1;
    bool done = (!idx);
    for(int i=0; i<n; i++) if(!vis[i]){ done=0; break; }
    if(done) {
        ok = 1;
        return;
    }

    for(int to : e[idx])if(!vis[to]){
        solve(to);
    }

    vis[idx] = 0;
    return;
}

int main(){
    
    cin >> n >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    solve(0);
    for(int to: e[0])solve(to);
    cout << ok;
return 0;}