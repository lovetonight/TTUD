// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;
#define N 1000001

int n;
int arr[N];
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
int solve()
{
    int count = 0;
    for (int i = 1; i < n - 1; i++)
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            count += 1;
    return count;
}

int main()
{
    input();
    cout << solve();
    return 0;
}