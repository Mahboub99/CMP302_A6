//
// Created by Dandosh on --/10/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

const int MAXN = 2e5 + 5;

bool adj[101][101];
int ans, n, m, mask[101];

void solve(int idx = 0)
{
    if (idx == n)
    {
        int res = 0, fail = 0;
        for (int i = 0; i < n; i++)
            if (mask[i])
            {
                res++;
                for (int j = i + 1; j < n; j++)
                {
                    if (mask[j] && !adj[i][j])
                        fail = 1;
                }
            }

        if (!fail)
            ans = max(ans, res);
        return;
    }

    solve(idx + 1);

    mask[idx] = 1; // try to take it
    solve(idx + 1);
    mask[idx] = 0; // remove it after returning
}

int main()
{
    IO;
    cin >> n >> m;
    for (int i = 0, fr, to; i < m; i++)
    {
        cin >> fr >> to;
        adj[fr][to] = adj[to][fr] = 1;
    }

    solve();
    cout << ans << endl;

    return 0;
}