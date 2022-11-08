// Dao Trong Hoan
// 20204974
// Range Minimum Query
// O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

int check[30][1000000]; // Luu chi so cua phan tu chua gia tri nho nhat
int arr[1000000];
int n;

void processing()
{
    for (int i = 0; i < n; i++)
        check[0][i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 1; (1 << j) < n; j++)
            check[j][i] = -1;
    for (int j = 1; (1 << j) < n; j++)
        for (int i = 0; i < n; i++)
        {
            if (arr[check[j - 1][i]] <= arr[check[j - 1][i + (1 << (j - 1))]])
                check[j][i] = check[j - 1][i];
            else
                check[j][i] = check[j - 1][i + (1 << (j - 1))];
        }
}
int rmp(int i, int j)
{
    int k = log2(j - i + 1);
    int b = 1 << k;
    return min(arr[check[k][i]], arr[check[k][j - b + 1]]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    processing();
    int m, L, R, sum = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L;
        cin >> R;
        sum = sum + rmp(L, R);
    }
    cout << sum;
    return 0;
}