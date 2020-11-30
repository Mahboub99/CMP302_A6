#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> teams;
vector<int> nodes;

vector<vector<int>> graph(20, vector<int>(20, 0));
bool check(vector<int> t)
{
    for (int i = 0; i < t.size(); i++)
        for (int j = i + 1; j < t.size(); j++)
            if (!graph[t[i]][t[j]])
                return false;
    return true;
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
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;
        graph[first][second] = graph[first][second] = 1;
    }
    for (int i = 0; i < V; i++)
    {
        nodes.push_back(i);
    }
    int ans = 1;
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
        if (check(t))
        {
            teams.push_back(t);
            ans = max(ans, (int)t.size());
        }
    }
    cout << ans;
    return 0;
}