// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int mod = 1e9 + 7;
int dp[5001][10];
unordered_map<int,vector<int>> adj;

void fill(){
    adj[0] = {4,6};
    adj[1] = {8,6};
    adj[2] = {7,9};
    adj[3] = {4,8};
    adj[4] = {0,3,9};
    
    adj[6] = {0,1,7};
    adj[7] = {2,6};
    adj[8] = {1,8};
    adj[9] = {4,2};
}

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
    //fills adjacency list
    fill();
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