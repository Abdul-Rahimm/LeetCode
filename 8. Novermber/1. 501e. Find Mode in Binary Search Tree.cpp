/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int mx = 0;
        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* fr = q.front();
            q.pop();
            
            mp[fr->val]++;
            mx = max(mx, mp[fr->val]);
            
            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
            
        }
        
        
        for(auto &pair : mp){
            if(pair.second == mx)
                ans.push_back(pair.first);
        }
        
        return ans;
    }
};