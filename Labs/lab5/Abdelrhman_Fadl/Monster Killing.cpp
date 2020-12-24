
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
#include <ctime>

using namespace std;

#define ll long long
#define lop(i,n) for(int i=0; i<n; i++)


ll power(ll x, ll p, ll mod){
    if(p == 0)return 1;
    if(p & 1) return (x * power(x, p-1, mod)) % mod;
    ll y = power(x, p/2, mod);
    y = (y * y) % mod;
    return y;
}


ll const N = 1e5+10;
ll const INF = 1e18;
ll const mod = 1e9 + 7;

///////////////////////////////////////////////////////////////////

ll n, m, h[N], w[N]; 
pair<ll, ll> dp[N];

void memo(){
    for(int i=1; i<1e5; i++) dp[i]=make_pair(1e8, 1e8);

    dp[0] = make_pair(0, 0);
    for(int x=1; x<(1e5)+1; x++){
        ll canReach=x, minSteps=0;
        for(int i=0; i<m; i++){
            ll back = x - w[i];
            if(back < 0 || back == x)continue;

            if(dp[back].first == canReach){
                if(dp[back].second + 1 < minSteps) minSteps = dp[back].second + 1;
            }else if(dp[back].first < canReach){
                canReach = dp[back].first;
                minSteps = dp[back].second + 1;
            }
        }
        dp[x] = make_pair(canReach, minSteps);
    }
    return;
}

int main(){
    cin>> n;
    for(int i=0; i<n; i++) scanf("%lld", &h[i]);
    cin >> m;
    for(int i=0; i<m; i++) scanf("%lld", &w[i]);

    memo();

    for(int i=0; i<n; i++) printf("%lld %lld\n", dp[ h[i] ].first, dp[ h[i] ].second);

return 0;}
