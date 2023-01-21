// Dao Trong Hoan
// 20204974
// Compute C_k_n
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
vector<int> arr[1000];

/*int compute(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    int a = compute(k - 1, n - 1) % MOD;
    int b = compute(k, n - 1) % MOD;
    return a + b;
}*/

/*double C(double k, double n)
{

    if (k == 0)
        return 1;
    return double(n / k) * C(k - 1, n - 1);
}*/
int main()
{
    int n, k, res = 1;
    cin >> k >> n;
    arr[0].push_back(1);
    arr[1].push_back(1);
    arr[1].push_back(1);
    for(int i = 2; i <= 999; i++)
    {
        arr[i].push_back(1);
        for(int j = 1; j < i; j++)
        {
            arr[i].push_back((arr[i - 1][j - 1] + arr[i - 1][j]) % MOD);
        }
        arr[i].push_back(1);
    }
    /*for (int i = 1; i <= k; i++)
    {
        res = res * ((n - k + i) / i);
    }
    cout << (long long)res;*/
    cout<<arr[n][k];

    return 0;
}
