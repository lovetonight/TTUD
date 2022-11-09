// Dao Trong Hoan
// 20204974
// Binary

#include <bits/stdc++.h>
using namespace std;

int n, arr[10];
void Try(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i];
        cout << endl;
    }
    else
        for (int j = 0; j <= 1; j++)
        {
            arr[x] = j;
            Try(x + 1);
        }
}

int main()
{
    cin >> n;
    Try(0);
    return 1;
}
