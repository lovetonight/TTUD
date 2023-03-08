// Dao Trong Hoan
// 20204974
// Kruskal

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
vector<ii> T;
vector<iii> myvt;
int n, m;
int p[N], r[N];
int res = 0;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        myvt.push_back(iii(ii(u, v), w));
    }
}
void makeSet(int x)
{
    p[x] = x;
    r[x] = 0;
}
int find(int x)
{
    if (x == p[x])
        return x;
    else
        return find(p[x]);
}
void unify(int x, int y)
{
    if (r[x] > r[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (r[x] == r[y])
            r[y] = r[y] + 1;
    }
}
bool cmp(iii a, iii b)
{
    return a.second < b.second;
}
void solve()
{
    
    sort(myvt.begin(), myvt.end(), cmp);
    for (int x = 1; x <= n; x++)
        makeSet(x);
    for (int i = 0; i < m; i++)
    {
        int u = myvt[i].first.first;
        int y = myvt[i].first.second;
        int ru = find(u);
        int ry = find(y);
        if (ru != ry)
        {
            unify(ru, ry);
            T.push_back(myvt[i].first);
            res += myvt[i].second;
            if (T.size() == n - 1)
                break;
        }
    }
}
int main()
{
    input();
    solve();
    cout << res;
    return 0;
}