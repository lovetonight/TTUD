#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000000
int arr[MAX], n;

int main()
{
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum % MOD;
}