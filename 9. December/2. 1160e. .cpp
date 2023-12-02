// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int countCharacters(vector<string> &words, string chars)
{
    unordered_map<char, int> mp;
    unordered_map<char, int> copy;
    int count = 0;

    for (char i : chars)
        mp[i]++;

    for (string word : words)
    {
        bool status = true;
        copy.clear();
        for (char i : word)
        {
            copy[i]++;
            if (copy[i] > mp[i])
            {
                status = false;
                break;
            }
        }

        if (status)
            count += word.length();
    }

    return count;
}

int main()
{
    vector<string> words{"cat", "bt", "hat", "tree"};
    string chars = "atach";

    cout << countCharacters(words, chars) << endl;
}