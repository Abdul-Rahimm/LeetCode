// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

string largestGoodInteger(string num)
{
    string ans = "";
    int len = num.size();

    for (int i = 0; i < len - 2; i++)
    {
        if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
        {
            string ret;
            for (int j = i; j <= i + 2; j++)
                ret.push_back(num[j]);

            if (ans.empty())
                ans = ret;
            else
                ans = ans > ret ? ans : ret;
        }
    }

    return ans;
}

int main()
{
    cout << largestGoodInteger("6777133339") << endl;
    // cout << largestGoodInteger("2300019") << endl;
    // cout << largestGoodInteger("42352338") << endl;
}