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
#define lp(i, a, b) for (int i = (a); i < (b); i++)
#define lpi(i, b, a) for (int i = (b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define print(ans) cout << ans << endl
#define print2(a, b) cout << a << ' ' << b << endl
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
int MOD = 1e9 + 7;
const double PI = acos(-1.0);
#define print_prec(ans, num) cout << fixed << setprecision(num) << (ans) << endl
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

const int oo = 1e9;

int n, m;
const int N = 1e4 + 9;

int dp[N];
vi b, a;

int main()
{
  //freopen("read.txt", "r", stdin);
  //freopen("write.txt", "w", stdout);
  //IO;

  scanf("%d", &n);
  a = vi(n);
  lp(i, 0, n) scanf("%d", &a[i]);
  scanf("%d", &m);
  b = vi(m);
  lp(i, 0, m) scanf("%d", &b[i]);

  lp(i, 0, N) dp[i] = oo;
  dp[0] = 0;

  lp(i, 0, N)
  {
    lp(j, 0, m)
    {
      if (b[j] + i < N && dp[i] != oo)
      {
        dp[i + b[j]] = min(dp[i] + 1, dp[i + b[j]]);
      }
    }
  }

  lp(i, 0, n)
  {
    if (dp[a[i]] != oo)
      printf("0 %d\n", dp[a[i]]);
    else
    {
      lpi(j, a[i] - 1, 0)
      {
        if (dp[j] != oo)
        {
          printf("%d %d\n", a[i] - j, dp[j]);
          break;
        }
      }
    }
  }

  return 0;
}