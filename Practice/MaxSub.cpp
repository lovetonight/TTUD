// Dao Trong Hoan
// 20204974
//

#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int n;
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

int F(int i)
{
    if (i == 1)
    {
        S[1] = a[1];
        return S[1];
    }
    if (S[i] == INF)
    {
        int b = F(i - 1);
        if (b > 0)
            S[i] = b + a[i];
        else
            S[i] = a[i];
    }
    return S[i];
}
void solveTopDown()
{
    for (int i = 1; i <= n; i++)
        S[i] = INF;
    int res = INF;
    for (int i = 1; i <= n; i++)
    {
        int tmp = F(i);
        res = max(res, tmp);
    }
    cout << res;
}
int main()
{
    input();
    solveTopDown();
    return 0;
}