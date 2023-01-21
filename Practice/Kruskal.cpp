// Dao Trong Hoan
// 20204974
// Minimum Spanning Tree - Kruskal
#include <bits/stdc++.h>
using namespace std;
const int M = 100007;
int n, m;
int u, v, w;
vector<int> myvt[M];
typedef pair<int, int> mypair;
map<mypair, int> mymap;
bool check[M];
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        myvt[u].push_back(v);
        myvt[v].push_back(u);
        mymap[make_pair(u, v)] = w;
        cout << mymap[make_pair(u, v)] << endl;
    }
}
void process()
{

}
int main()
{
    input();
    sort()
    return 0;
}
