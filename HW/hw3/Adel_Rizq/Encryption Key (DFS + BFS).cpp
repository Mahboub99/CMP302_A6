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

int n, k, arr[MAXN];
vector<int> adj[MAXN];

int calc_depth(int node)
{
    int ret = 0;
    for (auto v : adj[node])
        ret = max(ret, calc_depth(v));

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

    int depth = calc_depth(0);
    vector<int> mini(depth, 1e9);
    vector<ll> sums(depth);

    queue<int> q;
    q.push(0);
    int lvl = 0;

    while (q.size())
    {
        int szo = q.size();

        while (szo--)
        {
            int top = q.front();
            q.pop();

            mini[lvl] = min(mini[lvl], arr[top]);
            sums[lvl] += arr[top];

            for (auto i : adj[top])
                q.push(i);
        }

        lvl++;
    }

    string ans;
    int cur = 0, l = arr[0] % depth;
    while (cur < depth)
    {
        ans += to_string(sums[cur]);
        cur += max(1, mini[l] % depth);
    }

    cout << ans << endl;
    return 0;
}