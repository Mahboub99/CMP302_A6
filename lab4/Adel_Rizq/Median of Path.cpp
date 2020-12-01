//
// Created by Dandosh on --/11/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXN = 2e5 + 5;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

ll n, m, arr[MAXN], ans;
vector<int> adj[MAXN];
ordered_set os;

void dfs(int node = 0, int depth = 0) {
    os.insert({arr[node], node});

    if (depth % 2 == 0)
        ans += (*os.find_by_order(depth / 2)).first == arr[node];

    for (auto v : adj[node])
        dfs(v, depth + 1);

    os.erase({arr[node], node});
}

int main() {
    IO;
    cin >> n;
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