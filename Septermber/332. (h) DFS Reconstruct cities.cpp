#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

unordered_map<string fromcity, vector<string>> adj;
vector<string> ans;
int numtickets;

bool DFS(string from, vector<string> &path){
    path.push_back(fromcity);

    if(path.size() == numtickets + 1){
        ans = path;
        return true;
    }

    //this vector contains places u can go to from 'from_city'
    vector<string>& can_go = adj[from];

    for(int i = 0 ; i < can_go.size() ; i++){
        //going from 'fromcity' to 'tocity'
        string tocity = can_go[i]; 

        //remove this city to avoid cycle
        can_go.erase(can_go.begin+i);

        //explore
        if(DFS(tocity, path) == true)
            return true;

        //insert back
        can_go.insert(can_go.begin+i, tocity);
    }

    path.pop_back();
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    numtickets = tickets.size();

    //populate the adjacency list
    for(auto &pair : tickets){
        string u = tickets[0];
        string v = tickets[1];

        adj[u].push_back[v];
    }

    //sort for lexical
    for(auto &edge : adj){
        sort(edge.second.begin(),edge.second.end());
    }

    vector<string> path;
    DFS("JFK",path);

    return ans;
}


int main(){

    

}