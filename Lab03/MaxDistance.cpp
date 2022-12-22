// Dao Trong Hoan
// 20204974
// Max Distance Sub-sequence

#include <bits/stdc++.h>
using namespace std;
#define N 100000
long arr[N];
int n, c, m;

void MergeSort(long arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    long b[N];
    for (int k = l; k <= r; k++)
    {
        if (i > m)
        {
            b[k] = arr[j];
            j++;
        }
        else
        {
            if (j > r)
            {
                b[k] = arr[i];
                i++;
            }
            else
            {
                if (arr[i] < arr[j])
                {
                    b[k] = arr[i];
                    i++;
                }
                else
                {
                    b[k] = arr[j];
                    j++;
                }
            }
        }
    }
    for (int k = l; k <= r; k++)
        arr[k] = b[k];
}

void Merge(long arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        Merge(arr, l, m);
        Merge(arr, m + 1, r);
        MergeSort(arr, l, m, r);
    }
}

void search(long arr[], int l, int r)
{
    return arr[(l + r) / 2];
}
void process(long arr[], int n)
{
    Merge(arr, 0, n - 1);

    
}

void input()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> n >> c;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        process(arr, n);
    }
}

int main()
{
    input();
    return 0;
}