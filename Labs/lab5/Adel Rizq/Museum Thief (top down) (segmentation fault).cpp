//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 1e7 + 5;

ll n, arr[3][MAXN], dp[MAXN][3];

ll solve(int idx = 0, int prev = 0)
{
    if (idx >= n)
        return 0;

    ll &ret = dp[idx][prev];
    if (~ret)
        return ret;

    ret = solve(idx + 1, 0); // leave col
    if (prev != 1)
        ret = max(ret, solve(idx + 1, 1) + arr[1][idx]);
    if (prev != 2)
        ret = max(ret, solve(idx + 1, 2) + arr[2][idx]);

    return ret;
}

int main()
{
    IO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[1][i];
    for (int i = 0; i < n; i++)
        cin >> arr[2][i];

    memset(dp, -1, sizeof dp);
    cout << solve() << endl;

    return 0;
}