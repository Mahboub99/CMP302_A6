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

int n, m, e[N][N];
vector<int> ans;

int solve(int idx){
    if(idx == n){
        for(int i : ans)for(int j : ans)if(i != j && !e[i][j]){ return -1; }
        return ans.size();
    }

    int ret = solve(idx+1);
    ans.push_back(idx);
    ret = max(ret, solve(idx+1));
    ans.pop_back();
    return ret;
}

int main(){
    
    cin >> n >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        e[x][y] = 1;
        e[y][x] = 1;
    }

    cout << solve(0);

return 0;}