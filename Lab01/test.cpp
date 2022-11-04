#include <bits/stdc++.h>
using namespace std;
vector<int> vt[100000];

void ar(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[100000], n, m, L, R, x, sum = 0;
    // int *a = (int *)malloc(sizeof(int));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }
    ar(a,n);

    return 0;
}