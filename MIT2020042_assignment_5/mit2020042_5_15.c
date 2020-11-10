#include <stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

//struct Node* root=NULL,*ptr=NULL;

struct Node* createNode(int data){
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

struct Node* insert(struct Node* temp, int newNode){
    if(!temp) return createNode(newNode);
    
    if(temp->val > newNode)
        temp->left = insert(temp->left,newNode);
    else 
        temp->right = insert(temp->right,newNode);
        
    return temp;
}


void Depth(struct Node* root,int ans){
    if(!root) return;
    printf("%d   %d \n",root->val,ans);
    Depth(root->left,ans+1);
    Depth(root->right,ans+1);
    
}
int ans=0;
int height(struct Node* root){
    if(!root){ans=0;return 0;}
    
    int l=height(root->left);
    int r=height(root->right);
    printf("%d   %d\n",root->val,ans);
    if(l>r)ans=l+1;
    else ans=r+1;
    
    return ans;
}

int main(void) {
	// your code goes here
	struct Node* root=NULL;
	int n,c;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&arr[i]);
	    if(root==NULL)root=insert(root, arr[i]);
	    else insert(root, arr[i]);
	}
	printf("depth\n");
	printf("key depth\n");
    Depth(root,0);
    printf("height\n");
	printf("key height\n");
	height(root);
    return 0;
}
