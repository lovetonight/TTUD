// Dao Trong Hoan
// 20204974
// Check Bipartite Graph

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 2;
vector<int> arr[MAX];
int d[MAX];
int n, m;
queue<int> Q;

bool BFS(int s)
{
    d[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < arr[v].size(); i++)
        {
            int x = arr[v][i];
            if (d[x] > -1)
            {
                if ((d[v] + d[x]) % 2 == 0)
                    return false;
            }
            else
            {
                Q.push(x);
                d[x] = d[v] + 1;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        d[i] = -1;
    if (BFS(1))
        cout << 1;
    else
        cout << 0;
}