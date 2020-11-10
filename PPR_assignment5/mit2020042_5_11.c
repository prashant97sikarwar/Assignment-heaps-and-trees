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

TreeNode *search(TreeNode *root,int key){
    if (!root)
        return NULL;
    if (key == root->val)
        return root;
    else if(key > root->val)
        return search(root->right,key);
    else
        return search(root->left,key);
}
int Successor(TreeNode *node){
    node = node->right;
    while (node->left){
        node = node->left;
    }
    return node->val;
}

int Predecessor(TreeNode *node){
    node = node->left;
    while (node->right){
        node = node->right;
    }
    return node->val;
}


int main(){
    int N,key;
    scanf("%d %d", &N,&key);
    TreeNode* root = NULL;
    int val;
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        root = insertToBST(root, val);
    }
    TreeNode *node = search(root,key);
    printf("%d\n",Successor(node));
    printf("%d\n",Predecessor(node));
    return 0;
}