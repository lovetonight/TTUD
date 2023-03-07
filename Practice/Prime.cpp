// Dao Trong Hoan
// 20204974
// Kiểm tra số nguyên tố sử dụng sàng nguyên tố

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, m;
int arr[N];
int check[N];

void process() // Sàng nguyên tố
{
    memset(check, 0, sizeof(check));
    check[1] = 1;
    for (int i = 2; i <= 1e3 + 1; i++)
    {
        int j = i * i;
        while (j <= N)
        {
            check[j] = 1;
            j += i;
        }
    }
}
int main()
{
}