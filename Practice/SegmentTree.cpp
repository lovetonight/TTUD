// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

/*int n;
int arr[N];
int check[30][100000]; // Luu chi so cua phan tu chua gia tri nho nhat

void processing()
{

    // check[j][i] chỉ số của phần tử nhỏ nhất trong đoạn [i, i + 2^j - 1]
    for (int i = 0; i < n; i++)
        check[0][i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 1; (1 << j) < n; j++)
            check[j][i] = -1;
    for (int j = 1; (1 << j) < n; j++)
        for (int i = 0; i < n; i++)
        {
            if (arr[check[j - 1][i]] >= arr[check[j - 1][i + (1 << (j - 1))]])
                check[j][i] = check[j - 1][i];
            else
                check[j][i] = check[j - 1][i + (1 << (j - 1))];
        }
}

int rmp(int i, int j)
{
    int k = log2(j - i + 1);                                // Khoảng cách giữa 2 điểm cần kiểm tra
    int b = 1 << k;                                         // 2^k
    return max(arr[check[k][i]], arr[check[k][j - b + 1]]); // Trả về giá trị nhỏ nhất trong khoảng
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void process1(int u, int v) //To do: Cải tiến tính năng update
{
    arr[u] = v;
    for (int j = 1; (1 << j) < n; j++)
        for (int i = 0; i <=u; i++)
        {
            if (arr[check[j - 1][i]] >= arr[check[j - 1][i + (1 << (j - 1))]])
                check[j][i] = check[j - 1][i];
            else
                check[j][i] = check[j - 1][i + (1 << (j - 1))];
        }
}
int main()
{
    input();
    processing();
    int v;
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        string type;
        cin >> type;
        if (type == "update")
        {
            int u, v;
            cin >> u >> v;
            process1(u - 1, v);
        }
        if (type == "get-max")
        {
            int x, y;
            cin >> x >> y;
            cout << rmp(x - 1, y - 1) << endl;
        }
    }
    return 0;
}
*/

int n;
int arr[N];
int tree[4 * N];

void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}
int findMax(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = findMax(2 * node, start, mid, left, right);
    int p2 = findMax(2 * node + 1, mid + 1, end, left, right);
    return max(p1, p2);
}
void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    int v;
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (type == "get-max")
            cout << findMax(1, 1, n, x, y) << endl;
        if (type == "update")
            update(1, 1, n, x, y);
    }
    return 0;
}