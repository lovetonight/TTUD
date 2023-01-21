// Dao Trong Hoan
// 20204974
// GoldMining
#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int arr[N];
int n, L1, L2;
int F[N];
deque<int> Q;
void input()
{
    fstream fsi("test.txt", ios::in);
    cin >> n >> L1 >> L2;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        F[i] = arr[i];
    }
    Q.push_back(1);
}
// int Max(int i)
// {
//     int ans = 0;
//     for (int j = i - L2; j <= i - L1; j++)
//     {
//         int A;
//         if (j <= 0)
//             A = arr[i];
//         else
//             A = arr[i] + F[j];
//         ans = max(ans, A);
//     }
//     // cout<<ans<<endl;
//     return ans;
// }

void solve()
{

    for (int i = L1 + 1; i <= n; i++)
    {
        while (!Q.empty() && F[Q.back()] <= F[i - L1])
            Q.pop_back();
        Q.push_back(i - L1);
        while (!Q.empty() && Q.front() <= i - L2)
            Q.pop_front();
        F[i] = arr[i] + F[Q.front()];
    }
    int ans = F[1];
    for (int i = 2; i <= n; i++)
        ans = max(ans, F[i]);
    cout << ans;
}
int main()
{
    input();
    solve();
    return 0;
}