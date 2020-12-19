#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
typedef long long int ll;
#define SZ(c) ((ll)((c).size()))
#define REP(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define FOR(i, b, e) for (ll i = (ll)(b); i <= (ll)(e); ++i)
#define ALL(c) (c).begin(), (c).end()
#define MP(c, b) make_pair(c, b)
using namespace std;

int main(void)
{
    ll N, D, M;
    cin >> N >> D >> M;
    unordered_map<ll, ll> frc;
    unordered_map<ll, ll> cumulative_frc;
    ll sum = 0;
    for (ll i = 0; i < N; i++)
    {
        ll element;
        cin >> element;
        frc[element]++;
        cumulative_frc[element] += frc[element - D];
        if (M == 3)
            sum += cumulative_frc[element - D];
        else
            sum += frc[element - D];
    }
    cout << sum << endl;
    return 0;
}