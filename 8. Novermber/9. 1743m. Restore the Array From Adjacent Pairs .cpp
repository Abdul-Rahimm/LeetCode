class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> vis;
    
    
    void DFS(int source, vector<int> &ans){
        if(vis[source])
            return;
        
        vis[source] = true;
        ans.push_back(source);
        
        for(int neighbour : adj[source]){
            if(!vis[neighbour])
                DFS(neighbour, ans);
        }   
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        for(auto row: adjacentPairs){
            int u = row[0];
            int v = row[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);           
            
            vis[u] = false;
            vis[v] = false;
        }
        
        vector<int> start;
        int pos = 0;
        int index = 1;
        
        for(auto pair: adj){
            int u = pair.first;
            vector<int> neighbours = pair.second;
            
            if(neighbours.size() == 1){
                vector<bool> visited(adj.size(), false);
                DFS(u, start);
            }
            
        }
         return start;
    }
    
   
};