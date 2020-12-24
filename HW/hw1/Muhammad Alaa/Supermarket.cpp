#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int W, N, mx = 0;
    cin >> W;
    cin >> N;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i < pow(2, N); i++)
    {
        int index = 0, bitstring = i, sumv = 0, sumw = 0;
        while (bitstring > 0)
        {
            if ((bitstring & 1) == 1)
            {
                if (sumw + w[index] > W)
                {
                    mx = max(mx, sumv);
                    break;
                }
                else
                {
                    sumv += v[index];
                    sumw += w[index];
                }
            }
            index++;
            bitstring >>= 1;

            mx = max(mx, sumv);
        }
    }
    cout << mx;
    return 0;
}