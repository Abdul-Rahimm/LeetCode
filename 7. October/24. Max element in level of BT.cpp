#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> BFS(TreeNode* root){
        vector<int> level;
        queue<TreeNode*> q;
        
        if(root == NULL)
            return {};
        
        q.push(root);
        
        while(q.empty() == false){
            int n = q.size(); //size of level
            int max_element = INT_MIN;
            
            while(n--){
                
                TreeNode* front = q.front();
                q.pop();
                
                max_element = max(max_element,front->val);

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);  
            }
             
            level.push_back(max_element);
        }
        
        return level;
    }
    
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> level = BFS(root);
        
        return level;
    }
};