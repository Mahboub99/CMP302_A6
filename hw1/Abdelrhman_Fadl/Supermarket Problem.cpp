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

int w, n;
pair<int, int> v[30];

int solve(int idx = 0, int rem = w){
    if(idx == n) return 0;

    int ret = solve(idx+1, rem);
    if(rem >= v[idx].first)ret = max(ret, solve(idx+1, rem - v[idx].first) + v[idx].second);

    return ret;
}

int main(){
    
    cin >> w >> n;
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    cout << solve();

return 0;}