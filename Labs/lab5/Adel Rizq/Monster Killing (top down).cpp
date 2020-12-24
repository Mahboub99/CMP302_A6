//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int n, m, monsters[MAXN], shots[MAXN];
pair<int, int> dp[MAXN];

pair<int, int> solve(int health)
{
    auto &ret = dp[health];
    if (~ret.first) return ret;
    ret = {health, 0};

    for (int i = 0; i < m; i++)
    {
        if (shots[i] && health - shots[i] >= 0)
        {
            auto temp = solve(health - shots[i]);
            ret = min(ret, {temp.first, temp.second + 1});
        }
    }

    return ret;
}

int main()
{
    IO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> monsters[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> shots[i];

    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
        cout << solve(monsters[i]).first << ' ' << solve(monsters[i]).second << endl;

    return 0;
}
