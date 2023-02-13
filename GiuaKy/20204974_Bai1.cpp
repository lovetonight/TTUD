// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int n, k, m;
int arr[MAX];
int s = 0;
int dem = 0;

void input()
{
    fstream fsi("a.txt", ios::in);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {

        cin >> arr[i];
        if (i <= k)
            s += arr[i];
    }
    if (s == m)
        dem++;
}
void solve()
{
    for (int i = k + 1; i <= n; i++)
    {
        s = s - arr[i - k] + arr[i];
        if (s == m)
            dem++;
    }
    cout << dem;
}
int main()
{
    input();
    solve();
    return 0;
}