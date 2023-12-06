// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int totalMoney(int n)
{
    int ret = 0;
    int count = 28;
    int reps = 1;

    while (n > 7)
    {
        ret += count;
        count += 7;
        n -= 7;
        reps++;
    }

    while (n > 0)
    {
        ret += reps;
        reps++;
        n--;
    }

    return ret;
}
int main()
{
    cout << totalMoney(4) << endl;
    cout << totalMoney(10) << endl;
    cout << totalMoney(20) << endl;
}