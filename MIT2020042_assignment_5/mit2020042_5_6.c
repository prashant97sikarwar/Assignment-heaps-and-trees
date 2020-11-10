//find sum of all leaves in BST

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

int solution(TreeNode *root){
    if (root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    else
    {
       return solution(root->left) + solution(root->right);
    }
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
    printf("%d\n",solution(root));
    return 0;
}