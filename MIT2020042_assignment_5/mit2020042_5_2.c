//make bst and write preorder,postorder,inorder

#include <stdio.h>
#include <malloc.h>
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

void preorder(TreeNode *root){
    if (!root){
        return ;
    }
    printf("%d_",root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root){
    if (!root)
        return ;
    inorder(root->left);
    printf("%d_",root->val);
    inorder(root->right);    
}

void postorder(TreeNode *root){
    if (!root)
        return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d_",root->val);
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
    preorder(root);
    println();
    inorder(root);
    println();
    postorder(root);
    println();
    return 0;
}