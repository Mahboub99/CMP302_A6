
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


ll const N = 1e6+10;
ll const INF = 1e18;
ll const mod = 1e9 + 7;

///////////////////////////////////////////////////////////////////

ll n, v[N][2], dp[N][3];

int main(){
    cin>> n;
    for(int t=0; t<2; t++)for(int i=0; i<n; i++) scanf("%lld", &v[i][t]);

    for(int i=n-1; i>=0; i--){
        for(int x=0; x<3; x++) dp[i][2]=max(dp[i][2], dp[i+1][x]);
        dp[i][0] = max(dp[i+1][1], dp[i+1][2]) + v[i][0];
        dp[i][1] = max(dp[i+1][0], dp[i+1][2]) + v[i][1];
    }

    ll ans = 0;
    for(int i=0; i<3; i++) ans=max(ans, dp[0][i]);
    cout << ans;
return 0;}
