// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

#define vll vector<ll>
#define vi vector<int>
#define sz size()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(0),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())

using namespace std;
using ll = long long int;
using ld = long double;

int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int oo = INT_MAX;
const ll OO = 1e18;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll GCD(ll a, ll b) { return ((!b) ? a : GCD(b, a % b)); }

ll LCM(ll a, ll b) { return a / (GCD(a, b)) * b; }

double distance(double x1, double y1, double x2, double y2) { return hypot(fabs(x1 - x2), fabs(y1 - y2)); }

int comp_double(double a, double b) {
    if (fabs(a - b) <= EPS) return 0; // equal
    return (a < b) ? -1 : 1;
}

string Letters = "0123456789ABCDEF";

int toInt(char c) { return Letters.find(c); }

ll FromAnyBaseToDecimal(string inp, int base) {
    ll res = 0;
    for (int i = 0; i < inp.sz; i++) {
        res *= base;
        res += toInt(inp[i]);
    }
    return res;
}

string FromDecimalToAnyBase(ll n, int base) {
    if (n == 0) return "0";
    string ans = "";
    while (n) {
        ans = Letters[n % base] + ans;
        n /= base;
    }
    return ans;
}

const int N = 11;
int adj[N][N];

int checkCycle(vector<int> permutation) {
    permutation.push_back(0);
    permutation.insert(permutation.begin(), 0);

    int n = permutation.size();
    for (int i = 0; i < n - 1; i++) {
        int u = permutation[i];
        int v = permutation[i + 1];
        if (!adj[u][v]) {
            return 0;
        }
    }

//    cout << "Correct permutation" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << permutation[i] << " \n"[i == n - 1];
//    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    vector<int> permutation;
    for (int i = 1; i < n; i++) {
        permutation.push_back(i);
    }
    int ret = 0;
    do {
        if (checkCycle(permutation)) {
            ret = 1;
        }
    } while (next_permutation(all(permutation)));
    if (n == 1) {
        cout << 1 << endl;
    } else {
        cout << ((n != 2) ? ret : 0) << endl;
    }
}
