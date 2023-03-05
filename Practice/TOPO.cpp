// Dao Trong Hoan
// 20204974
// TOPO

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> A[N];
queue<int> Q;
int d[N];
int n, m;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        d[v]++;
    }
}
void topo()
{
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for (int i = 0; i < A[u].size(); i++)
        {
            int v = A[u][i];
            d[v]--;
            if (d[v] == 0)
                Q.push(v);
        }
    }
}
int main()
{
    input();
    topo();
    return 0;
}