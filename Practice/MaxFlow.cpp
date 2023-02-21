// Dao Trong Hoan
// 20204974
// Max Flow
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m; // Số đỉnh, số cạnh
int s, t; // Đỉnh nguồn, đích
int ans = 0;
int parent[N];
int f[N][N]; // Luồng hiện tại từ u đến v
int c[N][N]; //
vector<int> myvt[N];

// memset
void input()
{
    //fstream fsi("input.txt", ios::in);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
        myvt[u].push_back(v);
    }
}
// BFS
bool BFS()
{
    queue<int> myq;
    memset(parent, 0, sizeof(parent));
    myq.push(s);
    while (!myq.empty())
    {
        int u = myq.front();
        myq.pop();
        for (int i = 0; i < myvt[u].size(); i++)
        {
            int v = myvt[u][i];
            if (parent[v] == 0)
            {
                bool ok = false;
                if (c[u][v] > 0)
                {
                    if (f[u][v] < c[u][v])
                        ok = true;
                }
                else // Nếu không có đường từ u đến v
                {
                    if (f[v][u] > 0) // Có cạnh nghịch từ v đến u
                        ok = true;
                }
                if (ok)
                {
                    parent[v] = u;
                    myq.push(v);
                    if (v == t)
                        return true;
                }
            }
        }
    }
    return false;
}
void solve()
{
    int v = t;
    int delta = 1e9;
    while (parent[v] != 0)
    {
        int pv = parent[v];
        {
            if (c[pv][v] > 0)
            {
                delta = min(delta, c[pv][v] - f[pv][v]);
            }
            else
            {
                delta = min(delta, f[v][pv]);
            }
        }
        v = pv;
    }
    ans += delta;
    v = t;
    while (parent[v] != 0)
    {
        int pv = parent[v];
        if (c[pv][v] > 0)
        {
            f[pv][v] += delta;
        }
        else
        {
            f[v][pv] -= delta;
        }
        v = pv;
    }
}
void maxFlow()
{
    // Khởi tạo luồng bằng 0
    for (int u = 1; u <= n; u++)
        for (int j = 0; j < myvt[u].size(); j++)
        {
            int v = myvt[u][j];
            if (c[u][v] > 0)
                f[u][v] = 0;
        }
    // Tìm đường đi từ nguồn tới đích - BFS
    while (1)
    {
        bool ok = BFS();
        if (!ok)
            break;
        solve();
    }
    cout << ans;
}

// Ford Fulkerson

int main()
{
    input();
    maxFlow();
    return 0;
}