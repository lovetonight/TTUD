// Dao Trong Hoan
// 20204974
// Range Minimum Query
// O(n^2)

#include <bits/stdc++.h>
using namespace std;
vector<int> vt[1000000];

void preprocess(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        vt[i].push_back(i);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[vt[i].back()] < arr[j])
                vt[i].push_back(vt[i].back());
            else
                vt[i].push_back(j);
    }

}
int main()
{
    int a[100000], n, m, L, R, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    preprocess(a, n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L;
        cin >> R;
        sum = sum + a[vt[L].at(R - L)];
    }
    cout << sum;
    return 0;
}