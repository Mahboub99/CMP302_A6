#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<int> weight;
vector<int> value;

int solve(int idx = 0, int currentValue = 0, int currentWeight = 0)
{
    if (idx == n)
    {
        if (currentWeight <= w)
            return currentValue;
        return -1;
    }

    return max(solve(idx + 1, currentValue + value[idx], currentWeight + weight[idx]), solve(idx + 1, currentValue, currentWeight));
}

int main()
{
    cin >> w >> n;
    weight.resize(n);
    value.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int ans = solve();

    cout << ans << endl;

    return 0;
}