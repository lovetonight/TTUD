// Dao Trong Hoan
// 20204974
// Range Minimum Query
#include <bits/stdc++.h>
using namespace std;
int tree[100000];
int a[100000];
void makeNode(int L, int R, int index)
{
    int mid;
    if (L == R)
    {
        tree[index] = a[L];
        return;
    }
    mid = (L + R) / 2;
    makeNode(L, mid, 2 * index);
    makeNode(mid + 1, R, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}
int findMin(int u, int v, int L, int R, int index)
{
    int mid;
    if (u <= L && v <= R)
        return tree[index];
    mid = (L + R) / 2;
    if (v <= mid)
        return (findMin(u, v, L, mid, index * 2));
    if (u > mid)
        return (findMin(u, v, mid + 1, R, index * 2 + 1));
    return (min(findMin(u, v, L, mid, index * 2), findMin(u, v, mid + 1, R, index * 2 + 1)));
}
int main()
{
    int n, m, L, R, x, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    makeNode(1, n, 1);
    // cout << findMin(2, 10, 1, n, 1);
    for (int i = 1; i <= 2*n+1; i++)
    {
        cout << tree[i]<<" ";
    }
    /*cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L >> R;
        cout << findMin(L, R, 0, n - 1, 0) << "\n";
    }*/
    return 0;
}