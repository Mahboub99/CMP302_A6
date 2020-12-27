// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#include <bits/stdc++.h>

#define endl '\n'
#define sz size()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const ll OO = 1e18;
const int oo = INT_MAX;
const double EPS = 1e-9;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
  if (fabs(a - b) <= EPS) return 0; // equal
  return (a < b) ? -1 : 1;
}

int n, m;
const int N = 1e5 + 5;
const int M = 1e3 + 3;
ll a[N];
ll b[M];
ll dp[10010];

int main() {
  IO;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  ll mxHealth = 10001;
  fill(dp, dp + 10010, 1e17);
  dp[0] = 0;
  for (int i = 1; i <= mxHealth; i++) {
    for (int j = 0; j < m; j++) {
      if (b[j] <= i) {
        dp[i] = min(dp[i], 1 + dp[i - b[j]]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (dp[a[i]] == 1e17) {
      ll j = a[i];
      while (~j && dp[j] == 1e17) j--;
      cout << a[i] - j << ' ' << dp[j] << endl;
    } else {
      cout << 0 << ' ' << dp[a[i]] << endl;
    }
  }
}
