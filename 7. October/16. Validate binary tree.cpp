#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> child_parent;
        unordered_map<int,vector<int>> adj;
        
        for(int i = 0 ; i < n ; i++){
            
            int left  = leftChild[i];
            int right = rightChild[i];
            
            if(left != -1){
                //two parent condition
                if(child_parent.find(left) != child_parent.end())
                    return false;
                
                child_parent[left] = i;
                adj[i].push_back(left);
            }
            
            if(right != -1){
                if(child_parent.find(right) != child_parent.end())
                    return false;
                
                child_parent[right] = i;
                adj[i].push_back(right);
            }
        }

        int root = -1;
        for(int i = 0 ; i < n ; i++){
            
            if(child_parent.find(i) == child_parent.end()){
                if(root != -1)
                    return false;
                
                root = i;
            }
        }
        
        //no root condition
        if(root == -1)
            return false;
        
        queue<int> q; //for bfs
        int count = 1;
        vector<bool> visited(n,false);
        
        q.push(root);
        visited[root] = true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v : adj[u]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count == n;
        
        
        
        
    }
};