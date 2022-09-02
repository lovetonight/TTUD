#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, arr[MAX];
void nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
int maxRight(int i, int j)
{
    int s = 0, Max = arr[i];
    for (int x = i; x <= j; x++)
    {
        s = s + arr[x];
        if (s > Max)
            Max = s;
    }
    return Max;
}
int maxLeft(int i, int j)
{
    int s = 0, Max = arr[i];
    for (int x = j; x >= i; x--)
    {
        s = s + arr[x];
        if (s > Max)
            Max = s;
    }
    return Max;
}
int subSeqMax(int i, int j)
{
    if (i == j)
        return arr[i];
    int mid = (i + j) / 2;
    int ml = subSeqMax(i, mid);
    int mr = subSeqMax(mid + 1, j);
    int maxL = maxLeft(i, mid);
    int maxR = maxRight(mid + 1, j);
    int wM = maxL + maxR;
    return max(max(ml, mr), wM);
}
int main()
{
    nhap();
    cout << subSeqMax(0, n - 1);
}