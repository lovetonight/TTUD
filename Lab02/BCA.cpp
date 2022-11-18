// Dao Trong Hoan
// 20204974
// Balanced Course Assignment

#include <bits/stdc++.h>
using namespace std;

const int nMax = 11, mMax = 31;
int n, m, res = mMax;
int arr[nMax][mMax];
int M[mMax][mMax];
int load[nMax]; // Luu so mon hoc cua giao vien i
int x[mMax];    // Luu giao vien day mon i

void input()
{
    int k, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            arr[i][x] = 1;
        }
    }
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        cin >> y >> z;
        M[y][z] = 1;
        M[z][y] = 1;
    }
}
void solution()
{

}

void Try(int y)
{
    for (int i = 1; i <=n; i++)
    {
        if (arr[i][y] == 1)
        {
            x[y] = i;
            load[i]++;
            if (load[i] < res)
                Try(y + 1);
        }
        if (y == m) solution();
    else
    {
        if(load[])
    }
    }
    
}
int main()
{
    input();
    Try(1);
    cout << res;
}