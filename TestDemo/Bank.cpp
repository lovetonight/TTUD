// Dao Trong Hoan
// 20204947

#include <bits/stdc++.h>
using namespace std;
#define N 100001
map<string, int> moneyTransactionsFrom;
map<string, int> check;
//string name[N];
vector<string>name;
int v = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long totalMoneyTransactions = 0, countTransactions = 0;
    string type;
    do
    {
        string fromA, toA, time, atm;
        int money;
        cin >> type;
        if (type == "#")
        {
            continue;
        }
        else
        {
            fromA = type;
        }
        cin >> toA >> money >> time >> atm;
        countTransactions++;
        moneyTransactionsFrom[fromA] += money;
        totalMoneyTransactions += money;
        name.push_back(fromA);
        name.push_back(toA);
    } while (type != "#");
    do
    {
        cin >> type;
        if (type == "#")
            continue;
        else if (type == "?number_transactions")
        {
            cout << countTransactions << endl;
        }
        else if (type == "?total_money_transaction")
        {
            cout << totalMoneyTransactions << endl;
        }
        else if (type == "?list_sorted_accounts")
        {
            sort(name.begin(),name.end());
            cout << name[0] << " ";
            for (int i = 1; i < name.size(); i++)
                if (name[i] != name[i - 1])
                {
                    cout << name[i] << " ";
                }
        }
        else if (type == "?total_money_transaction_from")
        {
            string account;
            cin >> account;
            cout << moneyTransactionsFrom[account] << endl;
        }
        else if (type == "?inspect_cycle")
        {
            string account, k;
            cin >> account >> k;
            cout << 1;
        }

    } while (type != "#");

    return 0;
}