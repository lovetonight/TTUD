// Dao Trong Hoan
// 20204974

#include<bits/stdc++.h>
using namespace std;



int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    for(int i = 0; i < 5; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;

}