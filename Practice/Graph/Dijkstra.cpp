// Dao Trong Hoan
// 20204974
// Dijkstra

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int N = 1e5 + 1;
typedef pair<int, int> ii;
vector<ii> A[N];
int n, m;
bool visited[N];
int d[N];
int s, t;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(ii(v, w));
    }
}
int selectMin(set<int> &S)
{
    int min = INF;
    int u = -1;
    for (int i = 1; i <= n; i++)
    {
        if (S.find(i) != S.end() && d[i] < min)
        {
            min = d[i];
            u = i;
        }
    }
    return u;
}
void dijkstra()
{
    for (int v = 1; v <= n; v++)
        d[v] = INF;
    for (int i = 0; i < A[s].size(); i++)
    {
        int v = A[s][i].first;
        int w = A[s][i].second;
        d[v] = w;
    }
    set<int> S;
    for (int i = 1; i <= n; i++)
        S.insert(i);
    while (!S.empty())
    {
        int u = selectMin(S);
        S.erase(u);
        for (int i = 0; i < A[u].size(); i++)
        {
            int v = A[u][i].first;
            int w = A[u][i].second;
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
}
int main()
{
    input();
    cin >> s >> t;
    dijkstra();
    cout << d[t];
    return 0;
}