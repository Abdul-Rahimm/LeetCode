#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

unordered_map<int, vector<pr>> adj;
set<pair<int,int>> visited;

int BFS(int source, int target){
    queue<pr> q;
    int prev_bus = INT_MIN;
    int count = 0;
    
    for(pr pair: adj[source]){
        int d = pair.first;
        int bus = pair.second;
        q.push({d,bus});

        while(!q.empty()){
            int c = q.front().first;
            int bs = q.front().second;
            q.pop();

            if(bs != prev_bus)
                count++;

            visited.insert({c,bs});

            for(pr p : adj[c]){
                int a = p.first;
                int b = p.second;

                if(a == target)
                    return count;

                if(visited.find({a,b}) == visited.end()) 
                    q.push({a,b});
            }
            
            prev_bus = bs;
            
        }
    }

    return -1;
}
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    int bus = 1;
    for(vector<int> row: routes){
        int n = row.size();
        
        for(int i = 0 ; i < n-1 ; i++){
            int u = row[i];
            int v = row[i+1];
            
            adj[u].push_back({v,bus});
        }

        adj[row[n-1]].push_back({row[0],bus});
        bus++;   
    }   
    
    int ans = BFS(source,target);


    return ans;
}

int numBusesToDestination_MIK(vector<vector<int>>& routes, int source, int target) {
    if(source == target)
        return 0;
    
    unordered_map<int, vector<int>> adj;
    
    for(int i = 0 ; i < routes.size() ; i++){
        
        for(int num : routes[i]){
            adj[num].push_back(i);
        }
    }
    
    queue<int> q;
    vector<bool> visited(adj.size() + 1, false);
    
    for(int &route : adj[source]){
        q.push(route);
        visited[route] = true;
    }
    
    int bus = 1;
    
    while(!q.empty()){
        int s = q.size();
        
        while(s--){
            int route = q.front(); // route is index
            q.pop();
            
            //route k andar kon kon se stops
            for(int i : routes[route]){
                if(i == target)
                    return bus;
                
                for(int nextroute : adj[i]){
                    if(visited[nextroute] == false){
                        visited[nextroute] = true;
                        q.push(nextroute);
                    }
                }
                    
            }
        }
        bus++;
    }
    
    return -1;
    
}
int main(){
    vector<vector<int>> routes{{1,2,7},{3,6,7}};
    cout << numBusesToDestination(routes,1,6) << endl;
}
