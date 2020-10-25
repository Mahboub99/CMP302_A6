#include <bits/stdc++.h>
using namespace std;
#define IO                 \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0)
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define pf push_front
#define mem(a, b, s)           \
  for (int q = 0; q <= s; q++) \
    a[q] = b;
#define mem2(a, r, c, b)         \
  for (int q = 0; q <= r; ++q)   \
    for (int p = 0; p <= c; ++p) \
      a[q][p] = b;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define in insert
#define sc(x) scanf("%d", &x)
#define scl(a) scanf("%I64d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define rep(x, a, b) for (int x = a; x < b; ++x)
#define irep(x, a, b) for (int x = a; x > b; --x)

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> vvi;

const double pi = 3.14159265358979323846264338327950288419716939937510582097494459;
const double EPS = 1e-12;
const int meminf = 0x3f;
const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll modd = 998244353;
const int MAX = 1e7 + 5;
const int oo = 2e9 + 10;
const ll OO = 1e18 + 10;
const int N = 1e5 + 5;
const int logN = (int)(log2(N));

int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return ((a * b) / gcd(a, b)); }

/***********************************/
vvi adj;

bool visited[15];
int numVisited = 0;
int n, m;
bool ans = 0;

void dfs(int u)
{
  visited[u] = 1;
  numVisited++;

  for (auto v : adj[u])
  {
    if (v == 0 && numVisited == n)
      ans |= 1;

    if (!visited[v])
      dfs(v);
  }

  visited[u] = 0;
  numVisited--;
}

int main()
{
  IO;
  cin >> n >> m;
  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  adj.resize(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(0);
  int print = (ans) ? 1 : 0;
  cout << print << endl;
}