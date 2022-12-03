// Dao Trong Hoan
// 20204974
//

#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int n, ans;
int a[N];
int S[N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void solveBottomUp()
{
    S[0] = a[0];
    ans = a[0];
    for (int i = 1; i < n; i++)
    {
        if (S[i - 1] > 0)
        {
            S[i] = S[i - 1] + a[i];
        }
        else
            S[i] = a[i];
        ans = max(ans, S[i]);
    }
    cout << ans;
}
int main()
{
    input();
    // solveTopDown();
    solveBottomUp();
    return 0;
}