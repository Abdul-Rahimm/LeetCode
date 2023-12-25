// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
 string str;
    int n;
    int dp[101];
    
    int solve(int idx){
        if(idx == n){
            return 1; //one possible solution aka empty string has been found
        }
        
        if(str[idx] == '0'){
            return 0;   //this case cant be split
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int result = solve(idx+1);
        
        if(idx < n -1)
        if(str[idx] == '1'|| (str[idx] == '2' && str[idx+1] < '7')){
            result += solve(idx+2);
        }
        
        return dp[idx] = result;
    }
    
    int numDecodings(string s) {
        str = s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(0);
    }

