#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio; cin.tie(0); cout.tie(0)
#define ll long long

#define MOD 1000000007
#define  INF 1e9

using namespace std;

const int MAXN = 10010;
int n, m;
vector<int> Locations;
vector<int> visited;
int dp[MAXN][MAXN];

int solve(int i, int j) {
    if (i >= j - 1) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = INF;

    for (int k = i; k <= j; k++) {
        ret = min(ret, solve(i, k) + solve(k, j) + Locations[j] - Locations[i]);
    }

    return ret;
}

int main() {
// #ifndef ONLINE_JUDGE
//     //freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w+", stdout);
// #endif
//     IO;

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    Locations.resize(m + 2);

    Locations[0] = 0;
    Locations[m + 1] = n;
    for (int i = 1; i <= m; ++i) cin >> Locations[i];

    cout << solve(0, m + 1) << endl;

    return 0;
}