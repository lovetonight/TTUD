#include <bits/stdc++.h>
using namespace std;

void pad(string &x, string &y)
{
    int a = x.size();
    int b = y.size();
    if (a > b)
    {
        for (int i = 0; i < a - b; i++)
        {
            y.insert(0, "0");
        }
    }
    else if (b < a)
    {
        for (int i = 0; i < b - a; i++)
        {
            x.insert(0, "0");
        }
    }
}
void add(string &x, string &y)
{
    string tmp = "";
    int nho = 0;
    int a = x.size() - 1;
    while (a >= 0)
    {

        int sum = x[a] - '0' + y[a] - '0' + nho;
        if (sum >= 10)
        {
            nho = 1;
            sum = sum - 10;
        }
        char c = '0' + sum;
        tmp = c + tmp;
        a--;
        if (a < 0 && nho == 1)
        {
            tmp = '1' + tmp;
        }
    }
    
    cout << tmp << endl;
}
int main()
{
    string x;
    string y;
    cin >> x;
    cin >> y;
    pad(x, y);
    add(x, y);
}