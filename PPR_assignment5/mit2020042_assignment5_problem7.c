#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;

Node* newNode(int data); 
  
int search(int arr[], int strt, int end, int value); 
  
Node* buildUtil(int in[], int post[], int inStrt, 
                int inEnd, int* pIndex) 
{ 
    
    if (inStrt > inEnd) 
        return NULL; 
  
    Node* node = newNode(post[*pIndex]); 
    (*pIndex)--; 
  
    if (inStrt == inEnd) 
        return node; 
  
    int iIndex = search(in, inStrt, inEnd, node->data); 
  
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 
  
    return node; 
} 
  
Node* buildTree(int in[], int post[], int n) 
{ 
    int pIndex = n - 1; 
    return buildUtil(in, post, 0, n - 1, &pIndex); 
} 
int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main(){
    int n;
    scanf("%d",&n);
    int postorder[n];
    int inorder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&postorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    Node* root = buildTree(inorder, postorder, n); 
    preOrder(root); 
    return 0;
}