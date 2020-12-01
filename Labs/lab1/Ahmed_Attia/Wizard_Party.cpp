#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool flag = true; // First Loop

void Party(int** adj , int vCount , int vertex , bool* taken , int& ans)
{
    if(vertex == 0 && !flag )
    {
        for(int i = 0 ; i < vCount ; i++)
        {
            if(taken[i] == false)
            {
                ans = 0;
                return;
            }
        }

        ans = 1;
        return ;
    }
    else
    {
        flag = false;
    }
    

    for(int i = 0 ; i < vCount ; i++)
    {
        if( adj[vertex][i] == 1 && !taken[i] )
        {
            taken[i] = true;
            Party(adj , vCount , i , taken , ans);
            taken[i] = false;
        }
    }

    if( ans == 1)
        return;

    ans = 0;
    return ;
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
 
    bool* taken = new bool[N];
    for(int i = 0 ; i < N ; i++)
    {
        taken[i] = false;
    }

    int ans = 0;
    if(N == 1)
        ans = 1;
    else
        Party( adjMatrix , N , 0 , taken , ans);
    cout << ans;

    return 0 ;
}