#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, b, arr[MAX], maxRight[MAX], maxLeft[MAX];
void nhap()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void setMax()
{
    maxRight[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxRight[i] = max(arr[i], maxRight[i - 1]);
    }
    maxLeft[0] = arr[n];
    for (int i = n - 1; i > 0; i--)
    {
        maxLeft[i] = max(arr[i], maxLeft[i + 1]);
    }
}
int main()
{
    nhap();
    setMax();
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (maxRight[i] - arr[i] >= b && maxLeft[i] - arr[i] >= b)
        {
            result = max(maxRight[i] + maxLeft[i] - 2 * arr[i], result);
        }
    }
    cout << result;
}