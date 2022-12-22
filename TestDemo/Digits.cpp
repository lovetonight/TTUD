// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;
#define N 100001

int arr[7];
bool ktra[10];
int n, dem = 0;

int check(int arr[])
{
    int a = (arr[0] * 100 + arr[1] * 10 + arr[2]) - (arr[3] * 100 + 62) + (arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[2]);
    return a;
}

void Try(int x)
{
    for (int i = 1; i <= 9; i++)
    {
        if (!ktra[i])
        {
            arr[x] = i;
            ktra[i] = true;
            if (x == 6)
            {
                if (check(arr) == n)
                {
                    dem++;
                }
            }
            else
                Try(x + 1);
            ktra[i] = false;
        }
    }
}
int main()
{
    for (int i = 1; i <= 9; i++)
        ktra[i] = false;
    cin >> n;
    Try(0);
    cout << dem;
    return 0;
}