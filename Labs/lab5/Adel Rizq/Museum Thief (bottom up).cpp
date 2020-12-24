//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 1e6 + 5;

ll n, arr[3][MAXN], dp[MAXN][3];

int main()
{
    IO;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[1][i];
    for (int i = 1; i <= n; i++)
        cin >> arr[2][i];

    for (int i = 1; i < MAXN; i++)
    {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = max({dp[i - 1][0], dp[i - 1][2]}) + arr[1][i];
        dp[i][2] = max({dp[i - 1][0], dp[i - 1][1]}) + arr[2][i];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}