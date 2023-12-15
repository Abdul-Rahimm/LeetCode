// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

string destCity(vector<vector<string>> &paths)
{
    unordered_map<string, vector<string>> mp;
    unordered_set<string> st;

    for (vector<string> &row : paths)
    {
        string u = row[0];
        string v = row[1];

        st.insert(u);
        st.insert(v);

        mp[u].push_back(v);
    }

    for (string i : st)
    {
        if (mp.find(i) == mp.end())
        {
            return i;
        }
    }

    return "";
}
