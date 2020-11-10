//given a BST, Print out all the root to leaf paths

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

void PrintArray(int arr[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    println();
}

void RecurPath(TreeNode *root,int path[],int length){
    if (!root)
        return;
    path[length] = root->val;
    length++;
    if(root->left == NULL && root->right == NULL)
        PrintArray(path,length);
    else{
        RecurPath(root->left,path,length);
        RecurPath(root->right,path,length);
    }
}

void solution(TreeNode *root){
    int path[1000];
    RecurPath(root,path,0);
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
    solution(root);
    return 0;
}