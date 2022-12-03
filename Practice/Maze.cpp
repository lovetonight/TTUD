// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;
#define N 999
#define M 999
int n, m, r, c;
int arr[N][M];
int dX[] = {0, 1, 0, -1};
int dY[] = {-1, 0, 1, 0};
int dist[N][M];
int ans = -1;
typedef pair<int, int> ii;
queue<ii> qe;

void input()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
}
int solve()
{
    qe.push(ii(r, c));
    dist[r][c] = 0;
    arr[r][c] = 1;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u.first + dX[i];
            int y = u.second + dY[i];
            if (x < 1 || y < 1 || x > n || y > m)
            {
                return dist[u.first][u.second] + 1;
            }
            if (arr[x][y] != 1)
            {
                dist[x][y] = dist[u.first][u.second] + 1;
                qe.push(ii(x, y));
                arr[x][y] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    input();
    cout << solve();
    return 0;
}