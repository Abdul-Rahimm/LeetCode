// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    vector<vector<int>> ans;
    vector<int> row_values;

    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            row_values.push_back(matrix[j][i]);
        }

        ans.push_back(row_values);
        row_values.clear();
    }

    return ans;
}
