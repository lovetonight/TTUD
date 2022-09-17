#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, s[MAX], t[MAX], maxs[MAX];
void nhap()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> t[i];
}
int main()
{
    nhap();
    for (int i = 0; i < n; i++)
        maxs[t[i]] = t[i] - s[i];
    for (int i = 0; i < MAX; i++)
        maxs[i] = max(maxs[i], maxs[i - 1]);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (maxs[s[i] - 1] > 0)
        {
            ans = max(ans, maxs[s[i] - 1] + t[i] - s[i]);
        }
    }
    cout << ans;
}
