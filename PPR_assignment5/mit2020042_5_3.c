#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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

bool checkEqual(TreeNode *root1,TreeNode *root2){
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return root1->val == root2->val && (checkEqual(root1->left,root2->left) && checkEqual(root1->right,root2->right));
}


int main(){
    int t;
    int n;
    scanf("%d",&t);
    scanf("%d",&n);
    while(t--){
        int val;
        TreeNode *root1 = NULL;
        for(int j=0;j<n;j++){
            scanf("%d",&val);
            root1 =  insertToBST(root1,val);
        }
        TreeNode *root2 = NULL;
        for(int i=0;i<n;i++){
            scanf("%d",&val);
            root2 = insertToBST(root2,val);
        }
        if (checkEqual(root1,root2))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}