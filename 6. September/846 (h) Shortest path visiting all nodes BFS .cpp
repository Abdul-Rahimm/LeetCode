#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();

    if(n == 1)
        return 0;

    queue<pr>    q; // node,mask
    set<p> visited; // node,pathmake

    //BFS from all nodes
    for(int i = 0 ; i < n ; i++){

        int mask = (1 << i); // 0001
        q.push({i,mask});

        visited.insert({i,mask});

    }

    int all_visited_state = pow(2,n) - 1; //1111 (1 << n)

    int path = 0;

    while(!q.empty()){
        int size = q.size();
        path++; //first level

        //current level nodes
        while(size--){
            auto current = q.front();
            q.pop();

            int node = current.first;
            int mask = current.second;

            for(int adj : graph[node]){

                int next = adj;
                int nextmask = mask | (1 << adj); // mask or 

                if(nextmask == all_visited_state)
                    return path;

                if(visited.find({adj,nextmask}) == visited.end()){
                    visited.insert({adj,nextmask});
                    q.push({adj,nextmask});
                }
            }
        }
    }
    return -1;
}

int main(){
    

}