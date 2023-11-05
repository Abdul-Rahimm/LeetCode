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
    cin >> tc;
              
    while (tc--)
        solve();
              
    return 0;
}
int BFS(unordered_map<int,vector<int>> adj, int source){
    int levels = 0;
    vector<bool> vis(adj.size(),false);

    queue<int> q;
    q.push(source);
    

    while(!q.empty()){
        int nodes_current_level = q.size();

        for(int i = 0; i < nodes_current_level ; i++){
            int fr = q.front();
            q.pop();
            vis[fr] = true;

            for(int n: adj[fr]){
                if(vis[n] == false)
                    q.push(n);
            }
        }
        
        levels++;
    }

    return levels;
}


void solve(){
    unordered_map<int,vector<int>> adj;
    map<int,int> mp;
    int n = 4;
    cin >> n;

    for(int i = 0 ; i < n -1 ; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // adj[1].push_back(0);
    // adj[0].push_back(1);
    // adj[1].push_back(2);
    // adj[2].push_back(1);
    // adj[2].push_back(3);
    // adj[3].push_back(2);
    

    int current_level = 0;

    for(int i = 0 ; i < n ; i++){
        current_level = BFS(adj,i);

        mp[current_level]++;
    }

    for(auto pair:mp){
        cout << pair.second << endl;
        break;
    }



}