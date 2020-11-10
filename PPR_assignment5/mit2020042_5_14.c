#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>
#define println() printf("\n")

struct TreeNode{
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* newNode(int data) 
{ 
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
    node->val = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
TreeNode* insertLevelOrder(int arr[], TreeNode* root, 
                       int i, int n) 
{ 
    if (i < n) 
    { 
        TreeNode* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr,root->right, 2 * i + 2, n); 
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

    if((node->val == ls + rs)&& isSumTree(node->left) && isSumTree(node->right)) 
        return 1; 
  
   return 0; 
} 

int main(){
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf("%d", arr[i]);
    }
    TreeNode* root = insertLevelOrder(arr, root, 0, N);
    if (isSumTree(root))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}