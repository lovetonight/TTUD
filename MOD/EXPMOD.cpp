#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

unsigned long long sqr(unsigned long long x)
{
    return x * x;
}

unsigned long long pow(unsigned long long x, unsigned long long y)
{
    if (y == 0)
        return 1 % MOD;
    if (y % 2 == 0)
        return sqr(pow(x, y / 2)) % MOD;
    else
        return ((x % MOD) * (sqr(pow(x, y / 2)) % MOD)) % MOD;
}

int main()
{
    unsigned long long x, y;
    cin >> x >> y;
    cout << pow(x, y);
}