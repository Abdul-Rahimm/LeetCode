// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> ones_row(rows, 0);
    vector<int> ones_col(cols, 0);
    vector<vector<int>> ret(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                ones_row[i]++;
                ones_col[j]++;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ret[i][j] = ones_row[i] + ones_col[j] - (rows - ones_row[i]) - (cols - ones_col[j]);
        }
    }

    return ret;
}

int main()
{
    vvi mat{{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    vvi ans = onesMinusZeros(mat);
}