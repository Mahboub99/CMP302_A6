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

bool solve(vector<int>vec , int idx) {
    
    if (idx == n) return check(vec);

    bool ret = 0;
    for (int i = idx; i < n; i++) {
        swap(vec[idx], vec[i]);
        ret = max(ret ,solve(vec, idx + 1));
        swap(vec[idx], vec[i]);
    }
    return ret;
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
    vector<int>vec(n);
    for (int i = 0; i < n; i++)vec[i] = i;
    cout<<solve(vec , 0)<<endl;
    return 0;
}

