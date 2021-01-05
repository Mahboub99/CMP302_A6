//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int main()
{
    IO;
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, -1e18));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    // directions
    int dx[3] = {-1, -1, 0}, dy[3] = {0, -1, -1};

    // initialization
    dp[1][1] = grid[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 3; k++) // maximize the three directions
                dp[i][j] = max(dp[i][j], grid[i][j] + dp[i + dx[k]][j + dy[k]]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}