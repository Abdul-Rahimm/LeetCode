// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int rows, cols;

void solve(vector<vector<int>> &img, vector<vector<int>> &ret, int i, int j)
{
    int total = img[i][j];
    int count = 1;

    for (vector<int> dir : directions)
    {
        int u = dir[0];
        int v = dir[1];

        int new_i = i + u;
        int new_j = j + v;

        if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols)
        {
            total += img[new_i][new_j];
            count++;
        }
    }

    int value = floor(total / count);
    ret[i][j] = value;
}

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{

    rows = img.size();
    cols = img[0].size();
    vector<vector<int>> ret(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            solve(img, ret, i, j);
        }
    }

    return ret;
}

void print(vvi ans)
{
    for (vi row : ans)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main()
{
    vvi grid{{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
    vvi ans = imageSmoother(grid);
    print(ans);
}