// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int numSpecial(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    vector<int> vertical(cols);   // 4
    vector<int> horizontal(rows); // 3

    for (int i = 0; i < rows; i++)
    {
        int count = 0;
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 1)
                count++;
        }

        horizontal[i] = count;
    }

    for (int i = 0; i < cols; i++)
    {
        int count = 0;
        for (int j = 0; j < rows; j++)
        {
            if (mat[j][i] == 1)
                count++;
        }

        vertical[i] = count;
    }

    int ret = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == 1 && vertical[j] == 1 && horizontal[i] == 1)
                ret++;
        }
    }

    return ret;
}

int main()
{
    vector<vector<int>> mat{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    cout << numSpecial(mat) << endl;

    // vector<vector<int>> mat2{{1,0,0},{0,1,0},{0,0,1}};
    // cout << numSpecial(mat2) << endl;
}