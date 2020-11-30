#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

int n , m;
map<pair<int, int>, int>mp;

int check(vector<int> vec) {

    if (vec.size() == 1) return 1;

    if (!mp[{vec[0], vec[n - 1]}] && !mp[{vec[n - 1], vec[0]}]) return 0;

    for (int i = 1; i < n; i++) {
        if (!mp[{vec[i], vec[i - 1]}] && !mp[{vec[i - 1], vec[i]}]) return 0;
    }

    return 1;
}

bool solve() {
    vector<int>vec(n); 
    for (int i = 0; i < n; i++) vec[i] = i;
    
    do
    {
        if (check(vec)) return 1;

    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        mp[{u, v}]=1;
        mp[{v, u}]=1;
    }
    
    cout<<solve()<<endl;
    return 0;
}

