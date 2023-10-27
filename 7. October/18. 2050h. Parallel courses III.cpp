#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;

int N;
unordered_set<int> visited;
void find_local_max(vector<bool> &vis, int &max_time, vector<int> &time, int &count){
    int local_max = 0;
    
    for(int i = 0 ; i < N ; i++){//finding aik level ka max
        if(vis[i] && visited.find(i) == visited.end()){
            local_max = max(local_max,time[i]);
            
            visited.insert(i);
            count++;                             
        }
    }
    max_time += local_max;
}
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, vector<int>> dep;
    
    vector<bool> vis(n,true);
    int max_time = 0, count = 0;
    N = n;
    
    for(vector<int> row: relations){
        int u = row[0];
        int v = row[1];
        
        adj[u].push_back(v);
        dep[v].push_back(u);
        
        vis[v-1] = false; //dependant
    }
    
    here:
    find_local_max(vis,max_time,time,count); //for the initial roots
    
    for(int i = 0 ; i < n ; i++){ 
        bool status = false;
        
        if(!vis[i]){            //if not visited
            for(int x : dep[i]){ //check its dependants
                
                if(!vis[x])     //if dependant not vis. means dep needs to be visited
                    status = true;  
            } 
            
            
            bool in_set = true;
            if(!status){         //all deps visited. means ready
                for(int i : dep[i]){
                    if(visited.find(i) == visited.end()){
                            in_set = false;
                    }
                }

                if(in_set)
                    vis[i] = true;
            }
        }
    }
    
    if(count < n)
        goto here;

    
    return max_time;
}


int minimumTime_MIK(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        for(auto &vec : relations) {
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        vector<int> maxTime(n, 0); //maxTime[i] = maximum time taken by ith course to complete
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                maxTime[i] = time[i];
            }
        }
        
        while(!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                //Finishing time of v will depend on the maximum time of its pre-requisites
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }   
            }
        }
        
        return *max_element(begin(maxTime), end(maxTime));
    }

int main(){
    
    vii nums{{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time{1,2,3,4,5};

    cout << minimumTime(5,nums,time) << endl;

}

