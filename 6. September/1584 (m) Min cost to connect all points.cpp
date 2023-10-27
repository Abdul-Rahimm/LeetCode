//union find graphs MST
//prims algo 


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        map<int,int> mp;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto edge = pq.top();
            pq.pop();
            
            int cost = edge.first;
            int u    = edge.second;
            
            if(visited[u])
                continue;
            
            visited[u] = true;
            
            min_cost += cost;
            
            for(int v = 0 ; v < n ; v++){
                if(!visited[v]){
                    int distance =  abs(points[u][0] - points[v][0]) + 
                                    abs(points[u][1] - points[v][1]);
                    
                    if(mp.find(v) == mp.end() || distance < mp[v]){
                        mp[v] = distance;
                        pq.push({distance,v});
                    }
                }             
            }
        }
        return min_cost;
    }
};