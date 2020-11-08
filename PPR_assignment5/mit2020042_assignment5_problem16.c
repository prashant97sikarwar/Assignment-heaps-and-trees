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

void printInorder(TreeNode* node) 
{ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
  
    printf("%d ", node->val); 
  
    printInorder(node->right); 
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
    printInorder(root);
    return 0;
}