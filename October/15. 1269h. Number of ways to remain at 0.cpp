#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int s, len;
    int dp[501][501];
    
    int solve(int idx, int steps){
        
        if(steps == s && idx == 0)
            return 1;
        if(steps == s && idx != 0)
            return 0;
        if(idx < 0 || idx >= len)
            return 0;
        
        if(dp[idx][steps] != -1)
            return dp[idx][steps];
        
        int result = solve(idx-1,steps+1);
        result = (result + solve(idx,steps+1))   % mod;
        result = (result + solve(idx+1,steps+1)) % mod;
        
        return dp[idx][steps] = result;
        
    }
    
    
    int numWays(int steps, int arrLen) {
        arrLen = min(steps,arrLen);
        s = steps;
        len = arrLen;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0);
    }
};