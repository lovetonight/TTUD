// Dao Trong Hoan
// 20204974
// Binary

#include <bits/stdc++.h>
using namespace std;

int n, arr[20];
int dem = 0;
void in(int arr[])
{
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cout << endl;
}
void Try(int x)
{

    for (int j = 0; j <= 1; j++)
    {
        arr[x] = j;
        if (x == n)
        {
            in(arr);
            dem++;
        }
        else
            Try(x + 1);
    }
}

int main()
{
    cin >> n;
    Try(1);
}
