// Dao Trong Hoan
// 20204974

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int n;
int arr[MAX];
priority_queue<int> pq;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]);
    }
}

int main()
{
    string type;
    input();
    do
    {
        cin >> type;
        if (type == "*")
        {
            break;
        }
        if (type == "insert")
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        if (type == "delete-max")
        {
            cout << pq.top() << endl;
            pq.pop();
        }

    } while (type != "*");

    return 0;
}