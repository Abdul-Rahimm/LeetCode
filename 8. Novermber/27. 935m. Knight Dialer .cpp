// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int mod = 1e9 + 7;
int dp[5001][10];
vector<vector<int>> adj = {
    {4, 6},
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4}
};

int solve(int n, int cell){
    if(n == 0)
        return 1;
    
    if(dp[n][cell] != -1)
        return dp[n][cell];
    
    int result = 0;
    for(int &i : adj[cell]){
        result = (result + solve(n-1,i)) % mod;
    }
    
    return dp[n][cell] = result;
}

int knightDialer(int n) {
    
    memset(dp,-1,sizeof(dp));
    int result = 0;
    
    for(int i = 0 ; i <= 9 ; i++)
        result = (result + solve(n-1,i)) % mod;
    
    return result;
    
}
int main(){
    int n;
    cin >> n;

    cout << knightDialer(n);
}