#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int maxCycleWeight(int** adj , int vCount , int root , vector<int>Team )
{
    if( root == vCount )
    {
        bool FullCycleTeam = true;

        for (int i = 0; i < Team.size(); i++)
        { 
            for (int j = 0; j < Team.size(); j++)
            {
                if (i != j && adj[Team[i]][Team[j]]==0 )
                {
                    FullCycleTeam = false;
                }
            }
        }

        if (FullCycleTeam)
            return Team.size();
        else
            return 0;
    }
    
    Team.push_back(root);
    int a = maxCycleWeight(adj , vCount , root+1 , Team);

    Team.pop_back();
    int b = maxCycleWeight(adj , vCount , root+1 , Team);
  
    return max(a,b);
}

int main()
{
    int N , E;
    cin >> N >> E;

    int** adjMatrix = new int* [N];
    for(int i = 0 ; i < N ; i++)
    {
        adjMatrix[i] = new int [N];
        for(int j = 0 ; j < N ; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    int a , b;
    for(int i = 0 ; i < E ; i++)
    {
        cin >> a >> b;
        adjMatrix[a][b] = adjMatrix[b][a] = 1;
    }
 
    vector<int>Team;

    int ans = maxCycleWeight( adjMatrix , N , 0 , Team);
    cout << ans;

    return 0 ;
}