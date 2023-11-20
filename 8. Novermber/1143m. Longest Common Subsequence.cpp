// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
string a,b;
int asize,bsize;
int dp[1001][1001];

int solve(int i, int j){
    if(i == asize || j == bsize)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(a[i] == b[j])
        return dp[i][j] = 1 + solve(i+1,j+1);
    
        return dp[i][j] = max(solve(i,j+1), solve(i+1,j));
}

int longestCommonSubsequence(string text1, string text2) {
    memset(dp,-1,sizeof(dp));
    a = text1;  asize=a.size();
    b = text2;  bsize=b.size();
    
    return solve(0,0);
}

int main(){



}