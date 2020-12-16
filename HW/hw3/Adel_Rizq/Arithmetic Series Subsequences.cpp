//
// Created by Dandosh on --/11/2020.
//
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

const int MAXN = 2e5 + 5;

int main()
{
    IO;

    int n, m, d;
    cin >> n >> d >> m;
    unordered_map<int, ll> after, before;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        after[arr[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        before[arr[i]]++;

        if (m == 2)
        {
            if (after.count(x + d))
                ans += after[x + d];
        }
        else
        {
            if (after.count(x + d) && before.count(x - d))
                ans += before[x - d] * after[x + d];
        }

        after[arr[i]]--;
    }

    cout << ans << endl;
    return 0;
}