// Dao Trong Hoan
// 20204974
// TSP
#include <bits/stdc++.h>
using namespace std;
#define N 21
#define Max 1000000
#define oo 1e9

int arr[N][N];
int F[N][Max];
int n;
int x;
int last = oo;
void input()
{
    scanf("%d", &n);
    x = (1 << n) - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
}
bool checkContains(unsigned int S, int x)
{
    if (S & (1 << x))
        return true;
    else
        return false;
}
unsigned int removeElement(unsigned int S, int x)
{
    return S & (~(1 << x));
}
unsigned int addElement(unsigned int S, int x)
{
    return S | (1 << x);
}
int TSP(int i, unsigned int S)
{
    if (S == 0)
    {
        F[i][S] = arr[i][0];
    }
    else if (F[i][S] < 0)
    {
        F[i][S] = oo;
        for (int j = 1; j < n; j++)
            if (checkContains(S, j))
            {
                unsigned int Sj = removeElement(S, j);
                F[i][S] = min(F[i][S], TSP(j, Sj) + arr[i][j]);
            }
    }
    return F[i][S];
}

int main()
{
    input();
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= (1 << n) - 1; j++)
            F[i][j] = -2;
    x = removeElement(x, 0);
    cout << TSP(0, x);
    return 0;
}