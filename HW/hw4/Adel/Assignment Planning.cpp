//
// Created by Dandosh on --/12/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int main()
{
    IO;
    ll n, sum = 0;
    cin >> n;
    vector<int> d(n), p(n), idx(n);
    set<int> ava;

    for (int i = 0; i < n; i++)
        cin >> d[i], idx[i] = i, ava.insert(i + 1);
    for (int i = 0; i < n; i++)
        cin >> p[i], sum += p[i];

    sort(idx.begin(), idx.end(), [&](int i, int j) { return p[i] > p[j]; });

    for (int i = 0; i < n; i++)
    {
        auto first = upper_bound(ava.begin(), ava.end(), d[idx[i]]);
        if (first == ava.begin())
            continue;

        ava.erase(--first);
        sum -= p[idx[i]];
    }

    cout << sum << endl;
    return 0;
}