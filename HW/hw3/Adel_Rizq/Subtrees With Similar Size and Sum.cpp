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

ll n, m, k, arr[MAXN];
vector<int> adj[MAXN];
map<pair<ll, ll>, ll> summations;

pair<ll, ll> dfs(int node)
{
    pair<int, ll> ret = make_pair(1, arr[node]);

    for (auto v : adj[node])
    {
        auto temp = dfs(v);
        ret.first += temp.first;
        ret.second += temp.second;
    }

    if (ret.first > m)
        summations[ret]++;
    return {ret.first, ret.second};
}

int main()
{
    IO;
    cin >> n >> m;
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

    dfs(0);
    for (auto i : summations)
    {
        if (i.second > 1)
        {
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}