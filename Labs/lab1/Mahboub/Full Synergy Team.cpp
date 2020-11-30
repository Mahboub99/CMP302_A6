#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int n , m;
map<pair<int, int>, int>mp;

int check(vector<int> vec) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++) {
            if (i != j) {
                if (!mp[{vec[i], vec[j]}] && !mp[{vec[j], vec[i]}]) return 0;
            }
        }
    }
    return size;
}

int solve(int idx, vector<int>vec) {
    if (idx == n) {
        return check(vec);
    }
    int ret = 0;
    vector<int>vec2 = vec;
    vec2.push_back(idx);
    ret = max({ret , solve(idx + 1, vec2), solve(idx + 1, vec) });

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
    vector<int>vec;
    cout << solve(0, vec) << endl;

    return 0;
}
