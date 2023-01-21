// Dao Trong Hoan
// 20204974
// Shortest path

#include <bits/stdc++.h>
using namespace std;
const int M 100001;
struct Arc{
    int nod;
    int w;
    Arc(int _nod, int _w)
    {
        nod = _nod;
        w= _w;
    }
}
int n,m;
vector<Arc> A[N];
void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        A[u].push_back(Arc(u,w));
    }
    scanf("%d%d",&s,&t);
}
int selectMin()
void dijikstra()
{
    set<int>NonFixed;
    for(int v=1;v<=n;v++)
    {
        d[v]=INF;
        p[v]= s;
        for(int i=0;i<A[v].size();i++)
        {
            Arc a = A[s].
        }
    }
}

