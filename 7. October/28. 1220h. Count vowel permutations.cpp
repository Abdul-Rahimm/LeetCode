// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<long long> vi;
typedef vector<vi> vvi;
int mod = 1e9 + 7;
int a = 0, e = 1, i = 2, o = 3, u = 4;
vvi dp;

long long solve(int ch, int n){
    if(n == 0)
        return 1;
    if(dp[ch][n] != -1)
        return dp[ch][n];

    if(ch == a){
        return dp[ch][n] = solve(e, n-1) % mod;
    }
    else if(ch == e){
        return dp[ch][n] =  (solve(a,n-1) + solve(i,n-1)) % mod;
    }
    else if(ch == i){
        return dp[ch][n] =  (solve(a,n-1) + solve(e,n-1) + solve(o,n-1) + solve(u,n-1)) % mod;
    }
    else if(ch == o){
        return dp[ch][n] =  (solve(i,n-1) + solve(u,n-1)) % mod;
    }
    else{
        return dp[ch][n] =  (solve(a,n-1)) % mod;
    }

    return dp[ch][n] =  0;
}
int countvowel(int n){
    dp.resize(5, vector<long long> (n+1,-1));
    long result = 0;

    result = (result + solve(a,n-1)) % mod;
    result = (result + solve(e,n-1)) % mod;
    result = (result + solve(i,n-1)) % mod;
    result = (result + solve(o,n-1)) % mod;
    result = (result + solve(u,n-1)) % mod;
    
    return result;
}

int main(){
    cout << countvowel(2) << endl;
}