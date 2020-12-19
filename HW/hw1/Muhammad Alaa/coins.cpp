#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> a;
// this is first solution but i got time limite exceeded so i tried another solution
void coins(int t, int n, vector<bool> visted, int sum, int i, bool &flag)
{

    if (t < sum)
        return;

    if (sum == t || flag)
    {
        flag = true;
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (!visted[j])
        {
            visted[j] = true;
            coins(t, n, visted, sum + a[j], j + 1, flag);
            visted[j] = false;
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, T;
    bool r = false;
    cin >> T;
    cin >> N;
    a.resize(N);
    vector<bool> V(N, 0);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    coins(T, N, V, 0, 0, r);
    cout << r;
    return 0;
}
//itrative solotion
// int main()
// {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     int N, T;
//     cin >> T;
//     cin >> N;
//     if (T == 0)
//     {
//         cout << 1;
//         return 0;
//     }
//     vector<int> A(N);
//     for (int i = 0; i < N; i++)
//         cin >> A[i];
//     for (int i = 1; i < pow(2, N); i++)
//     {
//         int index = 0, bitstring = i, sum = 0;
//         while (bitstring > 0)
//         {
//             if ((bitstring & 1) == 1)
//             {
//                 sum += A[index];
//             }
//             index++;
//             bitstring >>= 1;
//         }
//         if (sum == T)
//         {
//             cout << true;
//             return 0;
//         }
//     }
//     cout << false;
//     return 0;
// }
