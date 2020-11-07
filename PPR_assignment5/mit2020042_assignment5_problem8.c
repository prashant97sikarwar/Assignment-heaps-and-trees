//construct full binary tree preorder and postorder tree

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
struct node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    if (*preIndex >= size || l > h)
        return NULL;
 
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
 
    if (l == h)
        return root;
 
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
 
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, 
                                        l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex, 
                                         i + 1, h, size);
    }
 
    return root;
}


struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}


int main(){
    int n;
    scanf("%d",&n);
    int preorder[n];
    int postorder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&postorder[i]);
    }
    struct node *root = constructTree(preorder, postorder, n);
    printInorder(root);
    return 0;
}