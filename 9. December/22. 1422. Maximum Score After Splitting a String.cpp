// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int maxScore(string s)
{
    int zeros = 0;
    int ones = 0;

    for (char i : s)
    {
        if (i == '1')
            ones++;
    }

    int ret = INT_MIN;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0')
            zeros++;
        else
            ones--;

        int total = zeros + ones;
        ret = total > ret ? total : ret;
    }

    return ret;
}