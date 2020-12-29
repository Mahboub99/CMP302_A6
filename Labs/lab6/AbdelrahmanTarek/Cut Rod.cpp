#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, string> mss;
#define re return
#define clr(x, v) memset(x, v, sizeof(x))
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define bn begin()
#define nd end()
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define NumofDigits(n) ((int)log10(n) + 1)
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sz size()
#define rep(i, v) for (int i = 0; i < v.sz; i++)
#define lp(i, a, b) for (ll i = ll(a); i < ll(b); i++)
#define lpi(i, b, a) for (ll i = ll(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define print(ans) cout << ans << endl
#define print2(a, b) cout << a << ' ' << b << endl
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
int MOD = 1e9 + 7;
const double PI = acos(-1.0);
#define print_prec(ans, num) cout << fixed << setprecision(num) << (ans) << endl
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

vector<vector<int>> dp;
vector<int> cuts;

int solve(int l, int r)
{
    if (r - l <= 1)
        return 0;
    int &ret = dp[l][r];
    if (~ret)
        return ret;
    int ans = 1e9;
    int cost = cuts[r] - cuts[l];
    for (int i = l + 1; i < r; i++)
        ans = min(ans, solve(l, i) + solve(i, r) + cost);
    return ret = ans;
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    IO;
    int n, m;
    cin >> n >> m;
    cuts = vector<int>(m);
    for (int i = 0; i < m; i++)
        cin >> cuts[i];
    cuts.pb(0);
    cuts.pb(n);
    sort(all(cuts));
    m += 2;
    dp = vector<vector<int>>(m, vector<int>(m, -1));
    cout << solve(0, m - 1) << endl;
    return 0;
}