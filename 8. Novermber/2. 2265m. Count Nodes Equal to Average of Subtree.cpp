#include<bits/stdc++.h>
using namespace std;


// A binary tree node has data, pointer to left child and a pointer to right child
struct node {
    int val;
    struct node* left;
    struct node* right;
};

// Helper function that allocates a new node with the given data and NULL left and right pointers.
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

int BFS_return(node* root){
        int val = 0;
        int count = 0;
        queue<node*> q;
        q.push(root);
        
        while(!q.empty()){
            node* fr = q.front();
            q.pop();
            
            val += fr->val;
            count++;

            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
        }
        return val/count;
    }
    
    int BFS(node* root){
        int count = 0;
        
        queue<node*> q;
        q.push(root);
        
        while(!q.empty()){
            node* fr = q.front();
            q.pop();
            
            if(fr->val == BFS_return(fr))
                count++;
            
            if(fr->left)
                q.push(fr->left);
            if(fr->right)
                q.push(fr->right);
        }
        
        return count;
    }
    
    int averageOfSubtree(node* root) {
       
        return BFS(root);
    }

int main(){    
    struct node* root = newNode(4);
    root->left = newNode(8);
    root->right = newNode(5);
    root->left->left = newNode(0);
    root->left->right = newNode(1);
    root->right->right = newNode(6);

    cout << averageOfSubtree(root) << endl; 

    
}
