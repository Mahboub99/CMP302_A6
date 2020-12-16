//
// Created by Dandosh on --/11/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

const int MAXN = 1e6 + 5;

int n, k, arr[MAXN], sums[MAXN];
vector<int> adj[MAXN], mini(MAXN, 1e9);

int dfs(int node, int depth = 0)
{
    int ret = 0;

    sums[depth] += arr[node];
    mini[depth] = min(mini[depth], arr[node]);

    for (auto v : adj[node])
        ret = max(ret, dfs(v, depth + 1));

    return ret + 1;
}

int main()
{
    IO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    char c;
    int p, ch;
    cin >> k;
    while (k--)
    {
        cin >> c >> p >> ch;
        adj[p].push_back(ch);
    }

    int depth = dfs(0);

    string ans;
    int cur = 0, l = arr[0] % depth;
    while (cur < depth)
    {
        ans += to_string(sums[cur]);
        cur += max(mini[l] % depth, 1);
    }

    cout << ans << endl;
    return 0;
}