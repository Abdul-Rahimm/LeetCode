// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


    string solve(TreeNode* root){
       if(root == NULL)
           return "";
        
        string ret = to_string(root->val);
        
        string left  = solve(root->left);
        string right = solve(root->right);
        
        if(root->left == NULL && root->right == NULL)
            return ret;
        
        if(root->left == NULL)
            return ret + "()(" + right + ")";
        
        if(root->right == NULL)
            return ret + "(" + left + ")";
        
        return ret + "("+left+")" + "("+right+")";        
    }
    
    string tree2str(TreeNode* root) {
        
        string ans = solve(root);
        
        return ans;
    }
