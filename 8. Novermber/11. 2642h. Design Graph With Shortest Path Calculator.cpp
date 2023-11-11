class Graph {
public:
    typedef pair<int,int> pr;
    unordered_map<int, vector<pr>> adj;
    int N;
    
    Graph(int n, vector<vector<int>>& edges) {
        N = n+1;
        for(vector<int> &row : edges){
            int u = row[0];
            int v = row[1];
            int w = row[2];
            
            adj[u].push_back({v,w});
        }
        
    }
    
    void addEdge(vector<int> row) {
        int u = row[0];
        int v = row[1];
        int w = row[2];

        adj[u].push_back({v,w});
    }
    
    int shortestPath(int source, int v) {
        priority_queue<pr, vector<pr> , greater<pr>> pq;
        
        vector<int> result(N, INT_MAX);
        result[source] = 0;
        pq.push({0, source});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto &v : adj[node]){
                int v_node = v.first;
                int v_dist = v.second;
                
                if(dist + v_dist < result[v_node]){
                    result[v_node] = dist + v_dist;
                    pq.push({dist + v_dist, v_node});
                }
            }
        }
        int ans = result[v] == INT_MAX ? -1 : result[v];
        return ans;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */