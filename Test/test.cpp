#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 1;
int n, c;
int arr[N];
int dem = 0;
map<int, int> m;
typedef pair<int, int> ii;
priority_queue<ii> pq;

bool checkvar(int distance)
{
    int count = 1;
    int i = 1;
    int last = 2;
    while (i < n)
    {
        while (last <= n && arr[last] - arr[i] < distance)
            last++;
        if (last <= n)
            count++;
        if (count >= c)
            return true;
        i = last;
        last++;
    }
    return false;
}

bool cmp(int a, int b)
{
    return a < b;
}

int MaxDistance()
{
    // int l = 0;
    // int r = arr[n] - arr[1];
    // while (l <=r)
    // {
    //     int mid = (l + r) / 2;
    //     if (checkvar(mid))
    //         l = mid + 1;
    //     else
    //         r = mid - 1;
    // }
    // return r;
    int mid = (arr[n] - arr[1]) / 2;
    int ans = 0;
    for (int i = 0; i <= mid + 1; i++)
    {
        if (checkvar(i))
            ans = i;
    }
    return ans;
}



int main()
{

    // fstream fsi("a.txt", ios::in);
    // int t;
    // fsi >> t;
    // while (t--)
    // {
    //     fsi >> n >> c;
    //     for (int i = 1; i <= n; i++)
    //         fsi >> arr[i];
    //     sort(arr + 1, arr + n + 1, cmp);
    //     cout << MaxDistance() << endl;
    // }

    proc2();

    return 0;
}
