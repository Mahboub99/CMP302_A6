//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second

const int MAXN = 2e5 + 5;

int n, m, dp[10001][10001];
vector<int> cuts;

int solve(int l = 0, int r = m + 1) {
    if (r - l <= 1) return 0;

    auto &ret = dp[l][r];
    if (~ret) return ret;
    ret = 2e9;

    for (int i = l + 1; i < r; i++)
        ret = min(ret, solve(l, i) + solve(i, r) + (cuts[r] - cuts[l]));

    return ret;
}

int main() {
    IO;
    cin >> n >> m;

    cuts.push_back(0);
    for (int i = 0, x; i < m; i++) cin >> x, cuts.push_back(x);
    cuts.push_back(n);

    memset(dp, -1, sizeof dp);
    cout << solve() << endl;
    return 0;
}