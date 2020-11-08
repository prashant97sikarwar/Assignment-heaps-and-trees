#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>
#define println() printf("\n")

struct TreeNode{
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insertToBST(TreeNode *root, int val){
    if(!root){
        TreeNode *node = (TreeNode *) malloc (sizeof(TreeNode));
        node -> val = val;
        node -> left = NULL;
        node -> right = NULL;
        return node;
    }
    if(val <= root -> val){
        root -> left = insertToBST(root -> left, val);
    }else{
        root -> right = insertToBST(root -> right, val);
    }
    return root;
}

bool printAncestors(TreeNode *root, int target) 
{ 
  if (root == NULL) 
     return false; 
  
    if (root->val == target)
        return true;
  
  if ( printAncestors(root->left, target) || 
       printAncestors(root->right, target) ) 
  { 
    printf("%d\n",root->val);
    return true;
  } 
  
  return false; 
} 

int main(){
    int N,target;
    scanf("%d %d", &N, &target);
    TreeNode* root = NULL;
    int val;
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        root = insertToBST(root, val);
    }
    printAncestors(root,target);
    return 0;
}