#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void AllPossibleRoads(vector<int> allHousesArr , int numberOfHouses , vector<int> currentHousesArr, vector< pair<int,int> > portals , bool& exist);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int numOfHouses;
    cin >> numOfHouses;

    int numOfPortals;
    cin >> numOfPortals;

    vector< pair<int,int> > Portals;

    for (int i = 0; i < numOfPortals; i++)
    {
        int w;
        int v;

        cin >> w;
        cin >> v;

        pair<int,int> myPair;
        myPair.first = w;
        myPair.second = v;

        Portals.push_back(myPair);
    }

    vector<int> allHousesArr(numOfHouses);
    for (int i = 0; i < numOfHouses; i++)
    {
        allHousesArr[i] = i;
    }


    vector<int> currentHousesArr;
    bool exist = false;

    if (numOfHouses == 1)
    {
        exist = true;
    }
    else
    {
        AllPossibleRoads(allHousesArr,numOfHouses,currentHousesArr,Portals,exist);
    }    

    cout << exist << endl;

    return 0;
}

void AllPossibleRoads(vector<int> allHousesArr , int numberOfHouses , vector<int> currentHousesArr, vector< pair<int,int> > portals , bool& exist)
{
    if (exist)
    {
        return;
    }
    
    if ( !currentHousesArr.empty())
    {
        if (currentHousesArr[0] != 0)
        {
            return;
        }
    }

    if (currentHousesArr.size() == numberOfHouses)
    {
        bool returnExists = false;
        bool portalExists = true;
        for (std::vector< int >::size_type i = 0; i < currentHousesArr.size()-1 && portalExists; i++)
        {
            bool twoWayExist = false;
            for (int j = 0; j < portals.size(); j++)
            {
                if(  (currentHousesArr[i] == portals[j].first && currentHousesArr[i+1] == portals[j].second) || (currentHousesArr[i] == portals[j].second && currentHousesArr[i+1] == portals[j].first) )
                {
                    twoWayExist = true;
                    break;
                }
            }
            if (!twoWayExist)
            {
                portalExists = false;
            }
        }    

        for (int i = 0; i < portals.size(); i++)
        {
            if(  (currentHousesArr[numberOfHouses-1] == portals[i].first && 0 == portals[i].second) || (currentHousesArr[numberOfHouses-1] == portals[i].second && 0 == portals[i].first) )
            {
                returnExists = true;
                break;
            }
        }

        if (portalExists && returnExists)
        {
            exist = true;
        }
        
    }
    
    for (std::vector< int >::size_type i = 0; i != allHousesArr.size(); i++)
    {
        int valueToBeErased = allHousesArr[i];

        currentHousesArr.push_back(allHousesArr[i]);

        allHousesArr.erase(allHousesArr.begin() + i);

        AllPossibleRoads(allHousesArr,numberOfHouses,currentHousesArr,portals,exist);

        allHousesArr.insert(allHousesArr.begin() + i, valueToBeErased);

        currentHousesArr.pop_back();

    }
    
}