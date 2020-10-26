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
int ans, n, m;

void solve(int idx = 0, int node = 0, int mask = 0)
{
    if (idx == n)
    {
        ans |= ((mask == (1 << n) - 1) && !node);
        return;
    }

    for (int i = 0; i < n; i++)
        if (adj[node][i] && ((1 << i) & mask) == 0)
        { // (i << i) & mask == 0  ==> check if I didn't take it before
            solve(idx + 1, i, mask + (1 << i));
        }
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
    cout << (ans || n == 1) << endl;

    return 0;
}