#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<ll, pair<ll, ll>>mp;
    
    ll n, d, m, x, ans = 0;
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        cin >> x; mp[x].first++;
        mp[x].second += mp[x - d].first;
        
        if (m == 2) ans += mp[x - d].first;
        else ans += mp[x - d].second;
    }
    cout << ans << endl;
    return 0;
}
