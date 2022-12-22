// Dao Trong Hoan
// 20204974
// TSP
#include <bits/stdc++.h>
using namespace std;
#define N 21
#define Max 1000000
#define oo 1e9

int ar[N][N];
int F[N][Max];
int arr[N];
int Final[N];
int n;
int x;
long long dem = 0;
int last = oo;
bool ktra[N];
void input()
{
    scanf("%d", &n);
    x = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &ar[i][j]);
}
int check(int arr[])
{
    return ar[0][arr[1]] + ar[arr[1]][arr[2]] + ar[arr[2]][arr[3]] + ar[arr[3]][arr[4]] + ar[arr[4]][arr[5]] + ar[arr[5]][arr[6]] + ar[arr[6]][arr[7]] + ar[arr[7]][arr[8]] + ar[arr[8]][arr[9]] + ar[arr[9]][arr[10]] + ar[arr[10]][arr[11]] + ar[arr[11]][arr[12]] + ar[arr[12]][0];
}
void Try(int x)
{
    for (int i = 1; i <= 12; i++)
    {
        if (!ktra[i])
        {
            arr[x] = i;
            ktra[i] = true;
            if (x == 12)
            {
                if (last > check(arr))
                {
                    last = check(arr);
                    for (int k = 1; k <= 12; k++)
                        Final[k] = arr[k];
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
    input();
    for (int i = 1; i <= 9; i++)
        ktra[i] = false;
    Try(1);

    cout << last;
    for (int i = 1; i <= 12; i++)
        cout << Final[i] << " ";
}