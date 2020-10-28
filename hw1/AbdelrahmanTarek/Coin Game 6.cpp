#include <bits/stdc++.h>
using namespace std;

int n;
int t;
int a[30];

bool solve(int idx = 0, int sum = 0)
{
    if (idx == n)
        return sum == t;
    return solve(idx + 1, sum) || solve(idx + 1, sum + a[idx]);
}

int main()
{
    cin >> t >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = solve();

    cout << ans << endl;

    return 0;
}