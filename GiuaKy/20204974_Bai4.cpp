// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
int n;
int arr[MAX];
int F[MAX];
typedef pair<int, int> ii;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        F[i] = arr[i];
    }
}

void solve()
{
    priority_queue<int> hd;
    hd.push(F[1]);
    for (int i = 3; i <= n; i++)
    {
        F[i] = F[i] + hd.top();
        hd.push(F[i - 1]);
    }
    int ans = F[1];
    for (int i = 1; i <= n; i++)
        ans = max(ans, F[i]);
    cout << ans;
}
int main()
{

    input();
    solve();
    return 0;
}