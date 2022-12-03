// Dao Trong Hoan
// 20204974
//

#include <bits/stdc++.h>
using namespace std;

#define N 10001
#define M 10001

int n, m;
int X[N], Y[M];
int S[N][N];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    for (int i = 1; i <= m; i++)
        cin >> Y[i];
}

void solveBottomUp()
{
    for (int i = 0; i <= n; i++)
        S[i][0] = 0;
    for (int j = 0; j <= m; j++)
        S[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                S[i][j] = S[i - 1][j - 1] + 1;
            }
            else
            {
                S[i][j] = max(S[i][j - 1], S[i - 1][j]);
            }
        }
    cout << S[n][m];
}
void solveTopDown()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        S[i][j]=-1;
}
int main()
{
    input();
    solveBottomUp();
}