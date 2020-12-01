#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void MaxNumOfTeams(vector<int> playersArr , vector< pair<int,int> > edges ,vector<int> synergyPlayers , int n, int numberOfTeam , bool& foundMax , int& numOfBestTeamPlayers );

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int numOfPlayers;
    cin >> numOfPlayers;

    int numOfSynergy;
    cin >> numOfSynergy;

    vector< pair<int,int> > Synergy;

    for (int i = 0; i < numOfSynergy; i++)
    {
        int w;
        int v;

        cin >> w;
        cin >> v;

        pair<int,int> myPair;
        myPair.first = w;
        myPair.second = v;

        Synergy.push_back(myPair);
    }

    vector<int> currentTeam(numOfPlayers);
    for (int i = 0; i < numOfPlayers; i++)
    {
        currentTeam[i] = i;
    }

    vector<int> synergyPlayers;
    bool foundMax = false;
    int numOfBestTeamPlayers = 0;
    int n =0;
    MaxNumOfTeams(currentTeam,Synergy,synergyPlayers,n,numOfPlayers,foundMax,numOfBestTeamPlayers);

    cout << numOfBestTeamPlayers << endl;

    return 0;
}

void MaxNumOfTeams(vector<int> playersArr , vector< pair<int,int> > edges ,vector<int> synergyPlayers , int n, int numberOfTeam , bool& foundMax , int& numOfBestTeamPlayers )
{
    /*if (foundMax)
    {
        return;
    }*/

    if (n == numberOfTeam)
    {
        bool isBestTeam = true;
        for (std::vector< int >::size_type i = 0; i < synergyPlayers.size() && isBestTeam; i++)
        {
            for (std::vector< int >::size_type j = i+1; j < synergyPlayers.size() && isBestTeam; j++)
            {
                bool goodEdge = false;
                for (std::vector< pair<int,int> >::size_type k = 0; k < edges.size() && isBestTeam; k++)
                {
                    if (  ((synergyPlayers[i] == edges[k].first && synergyPlayers[j] == edges[k].second) || (synergyPlayers[i] == edges[k].second && synergyPlayers[j] == edges[k].first)) )
                    {
                        goodEdge = true;
                        break;
                    }
                }
                isBestTeam = goodEdge;
            }
        }

        foundMax = isBestTeam;
        if (isBestTeam && synergyPlayers.size() > numOfBestTeamPlayers)
        {
            numOfBestTeamPlayers = synergyPlayers.size();
        }

        return;
    }


    synergyPlayers.push_back(playersArr[n]);
    MaxNumOfTeams(playersArr,edges,synergyPlayers,n+1,numberOfTeam,foundMax,numOfBestTeamPlayers);
    synergyPlayers.pop_back();

    MaxNumOfTeams(playersArr,edges,synergyPlayers,n+1,numberOfTeam,foundMax,numOfBestTeamPlayers);
}