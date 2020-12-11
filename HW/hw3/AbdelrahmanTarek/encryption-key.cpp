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
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sz size()
#define rep(i, v) for (ll i = 0; i < v.sz; i++)
#define lp(i, a, b) for (ll i = (a); i < (b); i++)
#define lpi(i, b, a) for (ll i = (b); i >= a; i--)
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
    cin.tie(NULL);
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};



ll n, m, e;
vll a;
vector<vll> adj;
unordered_map<ll, vll> mpo;
ll height = 0;

void dfs(ll u = 0, ll lv = 0) {
    for(auto v : adj[u]) {
        dfs(v, lv+1);
    } 
    mpo[lv].pb(a[u]);
    height = max(height, lv);
}

int main()
{
    //freopen("read.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    //IO;
    
    scanf("%lld", &n);
    a = vll(n);

    adj.resize(n, vll());

    lp(i,0,n) scanf("%lld", &a[i]);

    scanf("%lld", &e);

    while (e--)
    {   
        char c;
        ll u, v;
        scanf(" %c %lld %lld", &c, &u, &v);
        adj[u].pb(v);
    }    
    dfs();
    height++;

    ll l = a[0] % height;

    ll mn = 1e9;
    for (auto& u : mpo[l]) mn = min(mn, u);
    ll k = mn % height;
    if(!k) k = 1LL;

    ll i = 0;
    vll ans;
    while (i < height)
    {
        ll sum = 0;
        for(auto& u: mpo[i]) sum += u;
        printf("%lld", sum); 
        i += k;
    }
    printf("\n");    

    return 0;
}
