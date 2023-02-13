
// Dao Trong Hoan
// 20204974
#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int n, A, B;
int arr[MAX];
int sum;
int dem = 0;
void allPossibleSubset(int arr[], int n)
{
    int count = pow(2, n);
    for (int i = 0; i < count; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                sum += arr[j];
        }
        if (sum >= A && sum <= B)
            dem++;
    }
}

int main()
{
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    allPossibleSubset(arr, n);
    cout << dem;

    return 0;
}