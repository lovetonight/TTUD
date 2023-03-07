// Dao Trong Hoan
// 20204974
// Problem: Sum pair of sequence equal to a number
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, m;
int arr[N];

int main()
{
    memset(arr, 0, sizeof(arr));
    int count = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[x] = 1;
        if (arr[m - x] && 2 * x != m)
        {
            count++;
        }
    }
    cout << count;
}