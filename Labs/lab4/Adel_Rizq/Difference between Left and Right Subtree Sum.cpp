//
// Created by Dandosh on --/11/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXN = 1e6 + 5;
ll n, m, arr[MAXN], ans, r;
vector<int> adj[MAXN];

ll dfs(int node = 0) {
    ll left = 0, right = 0;

    if (adj[node].size() >= 1) left = dfs(adj[node][0]);
    if (adj[node].size() == 2) right = dfs(adj[node][1]);

    ans += (abs(left - right) <= r);
    return left + right + arr[node];
}

int main() {
    IO;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;
    char c;
    for (int i = 0, fr, to; i < m; i++) {
        cin >> c >> fr >> to;
        adj[fr].push_back(to);
    }

    dfs();
    cout << ans << endl;
    return 0;
}