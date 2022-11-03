// Dao Trong Hoan
// 20204974
// Range Minimum Query

#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int imin[MAX][MAX];

void preprocess(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        imin[i][i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)

            if (arr[imin[i][j - 1]] < arr[j])
                imin[i][j] = imin[i][j - 1];
            else
                imin[i][j] = j;
    }
}

int main()
{

    int a[10000], n, m, L, R, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(a, n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L;
        cin >> R;
        sum = sum + a[imin[L][R]];
    }
    cout << sum;
    return 0;
}