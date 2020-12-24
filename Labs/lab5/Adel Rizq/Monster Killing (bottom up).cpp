//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mini first
#define moves second

const int MAXN = 3e4 + 5;

int main()
{
    IO;
    int n, m;
    cin >> n;

    vector<int> monsters(n);
    for (int i = 0; i < n; i++)
        cin >> monsters[i];

    cin >> m;
    vector<int> shots;
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        if(x) shots.push_back(x); // don't push zeros
    }

    vector<pair<int, int>> dp(MAXN);
    for (int i = 0; i < MAXN; i++)
        dp[i] = {i, 0};

    for (int health = 0; health < MAXN; health++)
        for (auto shot : shots)
            if (health - shot >= 0) // mini -> first, moves -> second
                dp[health] = min(dp[health], {dp[health - shot].mini, dp[health - shot].moves + 1});

    for (auto i : monsters)
        cout << dp[i].mini << ' ' << dp[i].moves << endl;
    return 0;
}
