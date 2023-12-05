// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(int teamsadv)
{
    if (teamsadv == 1)
        return 0;

    int teams = teamsadv % 2 == 0 ? teamsadv / 2 : teamsadv / 2 + 1;
    int matches = teamsadv % 2 == 0 ? teamsadv / 2 : (teamsadv - 1) / 2;

    int ret = solve(teams) + matches;

    return ret;
}

int numberOfMatches(int n)
{

    return solve(n);
}