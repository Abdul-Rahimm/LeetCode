// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef array<int,2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;
 
void solve();
 
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
              
    while (tc--)
    solve();
              
    return 0;
}
 
void solve(){
    unordered_map<int,vector<int>> adj;
        vector<int> freq(n+1,0);
        
        for(auto &pair: trust){
            int u = pair[0];
            int v = pair[1];
            
            adj[u].push_back(v);
        }
        
        for(auto &pair: adj){
            int u = pair.first;
            
            for(int &v : adj[u]){
                freq[v]++;
            }
        }
    
    
    
    for(int i = 1 ; i <= n ; i++){
        if(freq[i] == n-1){
            if(adj[i].empty())
                return i;
        }
    }
        return -1;
     
    
}