#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int housesCount, portalsCount, h1, h2;
vector<int>* adj;

bool isTripPossible(int vtx, int mask = 0) {
    // Corner case : If there're no portals but 1 house only
    if (housesCount == 1 && portalsCount == 0)
        return true;
    // Passed by all the houses once
    if (mask == ((1 << housesCount) - 1))
        return true;
    // PROTECTION : Passing by the same house for the second time
    if (mask & (1 << vtx)) {
        return false;
    }
        
    // Visited
    mask |= (1 << vtx);

    // DFS
    bool result = false;
    for (auto it : adj[vtx]) {
        if (!(mask & (1 << it)) || it == 0) // Not Visited or returning home
            result |= isTripPossible(it, mask);
    }
    return result;
}

int main() {
    cin >> housesCount >> portalsCount;

    // Generate adjacency list
    adj = new vector<int>[housesCount];
    for (int i = 0; i < portalsCount; ++i) {
        cin >> h1 >> h2;
        adj[h1].push_back(h2);
        adj[h2].push_back(h1);
    }

    cout << isTripPossible(0) << '\n';
    
    return 0;
}
