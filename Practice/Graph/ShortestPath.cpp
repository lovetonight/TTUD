// Dao Trong Hoan
// 20204974
// Shortest path

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int oo = 1e9 + 1;
typedef pair<int, int> ii;
vector<ii> dist1[N];
int n, m;
int dist2[N];
priority_queue<ii> mypq;
int s, t;
void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist1[u].push_back(ii(w, v));
    }
    scanf("%d%d", &s, &t);
}
void dijkstra(int x, int y)
{
    int du, u, v;
    for (int i = 1; i <= n; i++)
        dist2[i] = oo;
    dist2[x] = 0;
    mypq.push(ii(0, x));
    while (!mypq.empty())
    {
        u = mypq.top().second;
        du = mypq.top().first;
        if (du != dist2[u])
            continue;
        mypq.pop();
        for (int i = 0; i < dist1[u].size(); i++)
        {
            v = dist1[u][i].second;
            if (dist2[v] > dist2[u] + dist1[u][i].first)
            {
                dist2[v] = dist2[u] + dist1[u][i].first;
                mypq.push(ii(dist2[v], v));
            }
        }
    }
    cout << dist2[y];
}

int main()
{
    input();
    dijkstra(s, t);
    return 0;
}
