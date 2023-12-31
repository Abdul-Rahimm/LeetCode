// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxLengthBetweenEqualCharacters(string s)
{
    int array[26] = {0};
    unordered_set<char> st;

    for (char i : s)
    {
        array[i - 'a']++;

        if (array[i - 'a'] > 1)
            st.insert(i);
    }

    if (st.size() == 0)
        return -1;

    int ans = 0;
    for (int i : st)
    {
        int first = 0;
        int last = s.size() - 1;

        while (s[first] != i && first < s.size())
        {
            first++;
        }
        while (s[last] != i && last > 0)
        {
            last--;
        }

        ans = max(ans, last - first - 1);
    }

    return ans;
}

int main()
{
    cout << maxLengthBetweenEqualCharacters("abcde") << endl;
}