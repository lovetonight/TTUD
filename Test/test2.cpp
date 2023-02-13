#include <bits/stdc++.h>
using namespace std;
map<int, int> x;
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;
    vector<int> vt;
    map<int, int> x;
    for (int i = 0; i < nums.size(); i++)
        x[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++)
        if (x[target - nums[i]])
        {
            vt.push_back(i);
            vt.push_back(x[target - nums[i]]);
            break;
        }
    return 0;
}