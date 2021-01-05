//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

ll n, arr[MAXN], dp[2][MAXN];
vector<int> adj[MAXN];

ll solve(bool taken = 0, int node = 0, int par = -1)
{
    ll &ret = dp[taken][node];
    if (~ret)
        return ret;
    ret = 0;

    ll take = 0, leave = 0;
    for (auto i : adj[node])
        if (i != par)
        {
            if (!taken)
                take += solve(1, i, node);
            leave += solve(0, i, node);
        }

    ret = max(leave, take + (arr[node] * !taken));
    return ret;
}

int main()
{
    IO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0, fr, to; i < n - 1; i++)
    {
        cin >> fr >> to;
        adj[fr].push_back(to);
        adj[to].push_back(fr);
    }

    memset(dp, -1, sizeof dp);
    cout << solve() << endl;

    return 0;
}