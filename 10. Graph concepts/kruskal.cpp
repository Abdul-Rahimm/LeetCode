#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
typedef vector<int> vi;

vi Rank(7, 0);
vi parent(7);
//DSU code
int find(int source){
    if(parent[source] = source)
        return source;

    return parent[source] = find(parent[source]);
}
void Union(int x, int y, vi& Rank, vi &parent){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent)
        return;

    if(Rank[x_parent] > Rank[y_parent])
        parent[y_parent] = x_parent;
    else if(Rank[y_parent > Rank[x_parent]])
        parent[x_parent] = y_parent;
    else    
        parent[y_parent] = x_parent;
}

void print_w(unordered_map<int,vector<pr>> adj){
    for (auto pair : adj) {
        int vertex = pair.first;
        vector<pr> neighbors = pair.second;

        cout << vertex << " -> ";
        for (pr neighbor : neighbors) 
            cout << neighbor.first << " " << neighbor.second << "   ";
        
        cout << endl;
    }
    cout << endl;
}
void add_edge(vector<vector<int>> adj,int u,int v,int w){
    // adj.push_back({v,u,w});
    adj.push_back({u,v,w});
}
int prims(unordered_map<int, vector<pair<int,int>>> adj){
    // min heap --> w node 
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    vector<bool> visited(adj.size(), false);

    pq.push({0,0});
    int result = 0;

    while(!pq.empty()){
        int w    = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node])       //node already visited -->do nothing
            continue;

        visited[node] = true;   //not visited. mark it visited
        result += w;

        for(auto pair: adj[node]){
            int node = pair.first;

            if(visited[node] == false){
                pq.push({pair.second, pair.first});
            }
        }
        
    }

    return result;    
}
int kruskal(vector<vi> &adj, vi &rank, vi& parent){
    int ans = 0;

    for(auto &vec : adj){
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];

        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u != parent_v){
            //not in the same component
            Union(u,v, rank, parent);
            ans += w;
        }      
    }

    return ans;
}


int main(){
    int n = 3;
    vector<vector<int>> weighted;

    for(int i = 0 ; i < 7 ; i++)
        parent[i] = i;
    
    add_edge(weighted,0,1,5);
    add_edge(weighted,1,2,5);
    add_edge(weighted,2,3,5);
    add_edge(weighted,3,0,20);

    add_edge(weighted,5,4,2);
    add_edge(weighted,5,6,2);
    add_edge(weighted,4,6,4);
    add_edge(weighted,3,4,1);
    
    auto comparater = [&](vi & vec1, vi &vec2){
        return vec1[2] < vec2[2];
    };

    sort(weighted.begin(), weighted.end(), comparater);
    
    return kruskal(weighted,Rank,parent);
}