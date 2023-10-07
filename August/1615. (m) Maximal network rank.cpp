#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef priority_queue<int> pqq;//max heap


int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    unordered_map<int, unordered_set<int>> adj;

    for(auto row: roads){
        int u = row[0];
        int v = row[1];
    
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int maxrank = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){

            int i_rank = adj[i].size();
            int j_rank = adj[j].size();

            int rank = i_rank + j_rank;

            if(adj[i].find(j) != adj[i].end())
                rank--;

            maxrank = max(maxrank,rank);
        } 
    }
    return maxrank;
}
int main(){
    vii nums{{0,1},{0,3},{1,2},{1,3}};
    cout << maximalNetworkRank(4,nums) << endl;
    
    vii nums1{{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << maximalNetworkRank(5,nums1) << endl;
}

