#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
vector<TreeNode*> help(int l,int r){
    if(l > r || l < 1){
        vector<TreeNode*> v;
        v.push_back(NULL);
        return v;
    }
    if(l == r){
        vector<TreeNode*> v;
        TreeNode* temp = new TreeNode(l);
        v.push_back(temp);
        return v;
    }

    vector<TreeNode*> ans;

    for(int i = l ; i <= r ; i++){

        vector<TreeNode*> lt = help(l,i-1);
        vector<TreeNode*> rt = help(i+1,r);

            for(int k = 0 ; k < lt.size() ; k++){
                for(int j = 0 ; j < rt.size() ; j++){
                    TreeNode* temp = new TreeNode(i,lt[k],rt[j]);
                    ans.push_back(temp);
                }
            }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    return help(1,n);
}

int main(){
    vector<TreeNode*> ans = generateTrees(3);

}