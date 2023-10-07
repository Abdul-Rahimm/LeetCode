// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int dp[59];
int solve(int n){
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    int result = INT_MIN;
    for(int i = 1 ; i <= n-1 ; i++){

        int product = i*max( n-i,solve(n-i) );
        result      = max(result,product);
    }

    return dp[n] = result;
} 

int integerBreak(int n) {
    memset(dp,-1,sizeof(dp));
    return solve(n);       
}

int main(){
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;
    
}