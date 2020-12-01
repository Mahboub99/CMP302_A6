#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;
#define       IO        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
#define lop(i, j, n)    for(int i = j; i<n; i++)
#define prl pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x)    (ll)((1ll)*(x.size()))
#define srt(x) sort(x.begin(),x.end())
#define pri pair<int,int>
#define EPS 1e-7
#define vll vector<ll>
#define vii vector<int>
#define pb push_back
#define oo                1000000100
#define OO                10000000000000100
#define PI atan(1.0)*4.0
#define sc(x) scanf("%d",&x)
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
const string alpha = "abcdefghijklmnopqrstuvwxyz";
ll const N = 16;
ll n, m, T, k;


vector<vector<ll>> genSubsets(ll &n, vector<ll>& arr) {
    vector<vector<ll>> res;
    vector<ll> temp;
    lop(i, 0, pow(2, n)) {
        temp.clear();
        lop(j, 0, n) { if (i & (1 << j)) { temp.push_back(arr[j]); }}
        res.push_back(temp);
    }
    return res;
}


int main() {
    IO;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    cin >> T;
    T=1;
    while (T--) {
        cin >> n >> m;
        vector<vii > mate(n, vii(n, 0));
        vll v;
        lop(i, 0, n) v.push_back(i);

        lop(i, 0, m) {
            int x, y;
            cin >> x >> y;
            mate[x][y] = 1;
            mate[y][x] = 1;
        }

        ll rr = 1;
        vector<vector<ll>> res = genSubsets(n, v);

        for (auto &subset:res) {
            ll cnt = 0;
            lop(i, 0, sz(subset)) {
                lop(j, 0, sz(subset)) {
                    if (mate[subset[i]][subset[j]])cnt++;
                }
            }
            if (cnt == (sz(subset) * (sz(subset) - 1)))rr = max(rr, sz(subset));
        }
        cout << rr << endl;
    }
    return 0;
}
