#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> teams;
vector<int> nodes;
void team(int n, vector<bool> visted, int &ans, int sum, int i)
{
    vector<int> vert;
    for (int l = 0; l < visted.size(); l++)
        if (visted[l])
            for (int m = 0; m < teams[l].size(); m++)
                vert.push_back(teams[l][m]);

    int size = vert.size();
    sort(vert.begin(), vert.end());
    vert.erase(unique(vert.begin(), vert.end()), vert.end());
    if (vert.size() < size)
        return;
    if (nodes.size() == vert.size())
    {
        ans = min(sum, ans);
        return;
    }

    for (int j = i; j < n; j++)
    {
        if (!visted[j])
        {
            visted[j] = true;
            bool flag = false;
            team(n, visted, ans, sum + 1, j + 1);
            visted[j] = false;
        }
    }
}

int main()
{
    int V, N;
    cin >> V >> N;
    if (N == 0)
    {
        cout << 1;
        return 0;
    }
    vector<vector<int>> graph(V, vector<int>());
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    for (int i = 0; i < V; i++)
    {
        nodes.push_back(i);
    }

    for (int i = 1; i < pow(2, nodes.size()); i++)
    {
        vector<int> t;
        int index = 0, bitstring = i;
        while (bitstring > 0)
        {
            if ((bitstring & 1) == 1)
            {
                t.push_back(nodes[index]);
            }
            index++;
            bitstring >>= 1;
        }
        bool flag1 = false;
        for (int k = 0; k < t.size(); k++)
        {
            int element = t[k];
            vector<int> friends = graph[element];

            for (int l = k + 1; l < t.size(); l++)
            {
                int element2 = t[l];
                for (int m = 0; m < friends.size(); m++)
                {
                    if (friends[m] == element2)
                    {
                        flag1 = true;
                        break;
                    }
                }
                if (flag1)
                {
                    break;
                }
            }
            if (flag1)
            {
                break;
            }
        }
        if (!flag1)
            teams.push_back(t);
    }
    int ans = 9;
    vector<bool> visted(teams.size(), 0);
    team(teams.size(), visted, ans, 0, 0);
    cout << ans;
    return 0;
}