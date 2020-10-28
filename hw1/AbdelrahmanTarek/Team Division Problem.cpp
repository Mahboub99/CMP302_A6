#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[10];
vector<int> teams[10];

int solve(int idx = 0)
{
    if (idx == n)
    {
        int teamsCount = 0;
        // check every team
        for (int i = 1; i <= 8; i++)
        {
            if (teams[i].size() >= 1)
                teamsCount++;
            for (size_t j = 0; j < teams[i].size(); j++)
            {
                for (size_t k = j + 1; k < teams[i].size(); k++)
                {
                    int u = teams[i][j];
                    int v = teams[i][k];
                    if (adj[u].find(v) != adj[u].end())
                        return INT_MAX; // not valid a answer
                }
            }
        }

        return teamsCount;
    }

    int ans = INT_MAX;

    // try every team
    for (int i = 1; i <= 8; i++)
    {
        teams[i].push_back(idx);
        ans = min(ans, solve(idx + 1));
        teams[i].pop_back();
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    int u, v;

    while (m--)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int ans = solve();

    cout << ans << endl;

    return 0;
}