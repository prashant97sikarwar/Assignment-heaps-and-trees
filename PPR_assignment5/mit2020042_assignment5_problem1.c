//make a bst and perform search operation k times//

#include <stdio.h>
#include <malloc.h>

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

int search(TreeNode *root, int val){
    if(!root) return 0;
    if(root -> val == val) return 1;
    if(val <= root -> val){
        return search(root -> left, val);
    }else{
        return search(root -> right, val);
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

    int K, e;
    scanf("%d", &K);
    for (int i = 0; i < K; i++){
        scanf("%d", &e);
        if(search(root, e)){
            printf("y\n");
        }else{
            printf("n\n");
        }
    }
    return 0;
}