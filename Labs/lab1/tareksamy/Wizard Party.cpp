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

int mate[N][N], vis[N];
bool solve(vll path) {
    if (sz(path) == n) {
        return (mate[0][path.back()] == 1);
    }
    bool ret = 0;
    lop(i, 0, n) {
        if (mate[i][path.back()] && !vis[i]) {
            path.push_back(i), vis[i] = 1;
            ret |= solve(path);
            vis[i] = 0, path.pop_back();
        }
    }
    return ret;
}


int main() {
    IO;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    memset(mate, 0, sizeof(mate));

    lop(i, 0, m) {
        int x, y;
        cin >> x >> y;
        mate[x][y] = 1, mate[y][x] = 1;
    }
    if (n == 1)cout << 1 << endl;
    else if (n == 2)cout << 0 << endl;
    else {
        vll tmp;
        tmp.push_back(0);
        vis[0] = 1;
        cout << solve(tmp) << endl;
    }
    return 0;
}
