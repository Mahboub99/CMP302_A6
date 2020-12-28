#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio; cin.tie(0); cout.tie(0)
#define ll long long

#define MOD 1000000007
#define  INF 1e18

using namespace std;


int main() {
// #ifndef ONLINE_JUDGE
//     //freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w+", stdout);
// #endif
//     IO;
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;

    return 0;
}
