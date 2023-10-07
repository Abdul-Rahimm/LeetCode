// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 

int MOD = 1e9 + 7;
int N,M,K;
int dp[51][51][101];
    
int solve(int idx,int searchcost,int maxsofar){
    if(idx == N){
        if(searchcost == K)
            return 1;
        return 0;
    }

    if(dp[idx][searchcost][maxsofar] != -1)
        return dp[idx][searchcost][maxsofar];
    
    
    int result = 0;
    for(int i = 1; i <= M ; i++){
        
        if(i > maxsofar)
            result = (result + solve(idx+1,searchcost+1,i)) % MOD;
        else
            result = (result + solve(idx+1,searchcost,maxsofar)) % MOD;

    }
    
    return dp[idx][searchcost][maxsofar] = result % MOD;   
}

int numOfArrays(int n, int m, int k) {
    N=n;
    M=m;
    K=k;
    
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0);
}
