#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
typedef vector<int> vi;

void print(unordered_map<int,vector<int>> adj){
    for (auto pair : adj) {
        int vertex = pair.first;
        vi neighbors = pair.second;

        cout << vertex << " -> ";
        for (int neighbor : neighbors) 
            cout << neighbor << " ";
        
        cout << endl;
    }
    cout << endl;
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

void add_edge(unordered_map<int,vector<int>> &adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);    //un-directed graph
}
void add_edge(unordered_map<int,vector<pair<int,int>> > &adj,int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});    //un-directed graph
}
 

void DFS(unordered_map<int,vector<int>> &adj,int u, vector<bool> &vis){
    //starts from 0
    if(vis[u])
        return;

    vis[u] = true;
    cout << u << " ";

    for(int v: adj[u]){
        if(vis[v] == false){
            DFS(adj,v,vis);
        }
    }
}
void BFS(unordered_map<int,vector<int>> &adj,int u, vector<bool> &vis){
    queue<int> q;
    q.push(u);
    cout << u  << " ";
    vis[u] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(vis[v] == false){
                q.push(v);
                vis[v] = true;
                cout << v << " ";
            }
        }
    }
}

void topological_DFS(unordered_map<int,vector<int>> &adj,int u, vector<bool> &vis,stack<int> &st){

    vis[u]= true;

    for(int &v:adj[u]){
        if(!vis[v])
            topological_DFS(adj,v,vis,st);
    }

    st.push(u);
}
void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
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
vector<int> dijkstra(unordered_map<int, vector<pair<int,int>>> &adj, int source){
    priority_queue<pr, vector<pr>, greater<pr> > pq;    //make a min heap of dist,node

    vector<int> result(adj.size(), INT_MAX);            //array of all nodes initially containing all infinities

    result[source] = 0;                                 //source to source is 0
    pq.push({0,source});                                //push in the queue

    while(!pq.empty()){
        int node = pq.top().second;                     //remove the top of queue
        int dist = pq.top().first;
        pq.pop();

        for(auto &v: adj[node]){                        //see where u can go from the top of the queue
            int v_node = v.first;
            int v_dist = v.second;

            if(dist + v_dist < result[v_node]){
                result[v_node] = dist + v_dist;
                pq.push({dist+v_dist, v_node});
            }
        }
    }

    return result;
}

int main(){
    int n = 3;
    unordered_map<int,vector<int>> adj;
    unordered_map<int, vector<pair<int,int>> > weighted;
    
    vector<bool> vis(n,false);
    stack<int> st;

    add_edge(weighted,0,1,5);
    add_edge(weighted,1,2,5);
    add_edge(weighted,2,3,5);
    add_edge(weighted,3,0,20);

    add_edge(weighted,5,4,2);
    add_edge(weighted,5,6,2);
    add_edge(weighted,4,6,4);
    add_edge(weighted,3,4,1);
    
    // print_w(weighted);
    cout << prims(weighted) << endl;
    
    // vector<int> ans_dijkstra = dijkstra(weighted,2);
   
    
    
    
}