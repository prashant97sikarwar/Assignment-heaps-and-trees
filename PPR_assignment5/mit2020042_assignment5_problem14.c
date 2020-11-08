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

int sum(TreeNode*root){
    if(!root){
        return 0;
    }
    else
    {
        return sum(root->left) + sum(root->right) + root->val;
    }
    
}

int isSumTree(TreeNode* node) 
{ 
    int ls, rs; 
  
    if(node == NULL || 
            (node->left == NULL && node->right == NULL)) 
        return 1; 
  
   ls = sum(node->left); 
   rs = sum(node->right); 

    if((node->val == ls + rs)&& 
            isSumTree(node->left) && 
            isSumTree(node->right)) 
        return 1; 
  
   return 0; 
} 

int main(){
    int N;
    scanf("%d", &N);
    TreeNode* root = NULL;
    int val;
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        root = insertToBST(root, val);
    }
    if (isSumTree(root))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}