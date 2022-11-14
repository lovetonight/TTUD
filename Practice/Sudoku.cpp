// Dao Trong Hoan
// 20204974
// Sudoku

#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int a = 0;

typedef pair<int, int> ii;

int cau_do[N][N] = {{7, 8, 0, 4, 0, 0, 1, 2, 0},
                    {6, 0, 0, 0, 7, 5, 0, 0, 9},
                    {0, 0, 0, 6, 0, 1, 0, 7, 8},
                    {0, 0, 7, 0, 4, 0, 2, 6, 0},
                    {0, 0, 1, 0, 5, 0, 9, 3, 0},
                    {9, 0, 4, 0, 6, 0, 0, 0, 5},
                    {0, 7, 0, 3, 0, 0, 0, 1, 2},
                    {1, 2, 0, 0, 0, 7, 4, 0, 0},
                    {0, 4, 9, 2, 0, 6, 0, 0, 7}};

void print()
{
    for (int i = 0; i < N; i++)
    {
        if (i != 0 && i % 3 == 0)
            cout << "-----------------------\n";
        for (int j = 0; j < N; j++)
        {
            if (j != 0 && j % 3 == 0)
                cout << "| ";
            cout << cau_do[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int v, int r, int c)
{
    for (int i = 0; i < 9; i++)
        if (cau_do[i][c] == v)
            return false;
    for (int i = 0; i < 9; i++)
        if (cau_do[r][i] == v)
            return false;
    for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
        for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
            if (cau_do[i][j] == v)
                return false;
    return true;
}

void find(int *x, int *y)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (cau_do[i][j] == 0)
            {
                *x = i;
                *y = j;
                return;
            }

    *x = -1;
}

void ktra()
{
    int x, y;
    find(&x, &y);
    if (x == -1)
    {
        if (a == 0)
            print();
    }
    else
        for (int i = 1; i < 10; i++)
        {
            if (check(i, x, y))
            {
                cau_do[x][y] = i;
                ktra();
                cau_do[x][y] = 0;
            }
        }
}

int main()
{
    ktra();
}
