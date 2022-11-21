// Dao Trong Hoan
// 20204974
// Balanced Course Assignment

#include <bits/stdc++.h>
using namespace std;

const int nMax = 31, mMax = 11, N = 50;
vector<int> T[N];
int n, m, res = 1e9;
int x[nMax];    // Giáo viên dạy môn thứ i
int load[mMax]; // Tải của giáo viên thứ i
bool conflict[nMax][nMax];

void input()
{
    cin >> m >> n;
    for (int t = 1; t <= m; t++)
    {
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            int y;
            cin >> y;
            T[y].push_back(t);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            conflict[i][j] = false;
    int K;
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = true;
        conflict[y][x] = true;
    }
}
bool check(int t, int k)
{
    for (int i = 1; i < k; i++)
        if (conflict[i][k] && x[i] == t)
            return false;
    return true;
}

void solution()
{
    int maxLoad = 0;
    for (int i = 1; i <= m; i++)
        maxLoad = max(maxLoad, load[i]);
    res = min(res, maxLoad);
}
void Try(int k)
{
    for (int i = 0; i < T[k].size(); i++)
    {
        int t = T[k][i];
        if (check(t, k))
        {
            x[k] = t;
            load[t]++;
            if (k == n)
                solution();
            else if (load[t] < res)
                Try(k + 1);
            load[t]--;
        }
    }
}

int main()
{
    input();
    for (int i = 1; i <= m; i++)
        load[i] = 0;
    Try(1);
    cout << res;
    return 0;
}
