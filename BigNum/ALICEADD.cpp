#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long a, b, c, a0, a1, b0, b1, c0, c1;
    cin >> a >> b;
    a1 = a % 10;
    a0 = a / 10;
    b1 = b % 10;
    b0 = b / 10;
    c1 = (a1 + b1) % 10;
    c0 = (a1 + b1) / 10;
    cout << a0 + b0 + c0 << c1 << endl;
}