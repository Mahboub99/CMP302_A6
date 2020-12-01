#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> nodes;
vector<vector<int>> graph(20, vector<int>(20, 0));
bool check(vector<int> t, vector<int> path, vector<bool> visted)
{
    bool flag = false;
    for (size_t i = 0; i < visted.size(); i++)
    {
        if (!visted[i])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        if (!graph[path[0]][0])
            return false;
        if (path[path.size() - 1] != 0)
            return false;
        for (size_t j = 0; j < (int)path.size() - 1; j++)
        {
            if (!graph[path[j]][path[j + 1]])
            {
                return false;
            }
        }
        return true;
    }
    bool ans = false;
    for (int i = 0; i < t.size(); i++)
    {
        if (!visted[i])
        {
            visted[i] = true;
            vector<int> tmp = path;
            tmp.push_back(i);
            ans = check(t, tmp, visted) || ans;
            visted[i] = false;
        }
    }
    return ans;
}
int main()
{
    int V, N;
    cin >> V >> N;
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;
        graph[first][second] = graph[second][first] = 1;
    }
    if (V == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < V; i++)
        nodes.push_back(i);
    int ans = 0;
    vector<bool> visted(V, 0);
    vector<int> path;
    ans = check(nodes, path, visted);
    cout << ans;
    return 0;
}