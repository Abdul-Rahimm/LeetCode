// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

bool odd(char i)
{
    return i == '1' || i == '3' || i == '5' || i == '7' || i == '9';
}

string largestOddNumber(string num)
{
    int len = num.size();
    int i = 0, save = -1;

    while (i < len)
    {
        if (odd(num[i]))
            save = i;

        i++;
    }

    if (save != -1)
        return num.substr(0, save + 1);
    else
        return "";
}

int main()
{
    cout << largestOddNumber("52") << endl;
    cout << largestOddNumber("4206") << endl;
    cout << largestOddNumber("35427") << endl;
}