
#include <malloc.h> 
#include <stdio.h> 

typedef struct Treenode { 
	int val; 
	struct Treenode* left; 
	struct Treenode* right; 
} node; 

node* insertToBST(node *root, int val){
    if(!root){
        node *node = (struct Treenode *)malloc(sizeof(struct Treenode));
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

node* createNode(int val) 
{ 
	node* newNode = (node*)malloc(sizeof(node)); 
	newNode->val = val; 
	newNode->left = NULL; 
	newNode->right = NULL; 
	return newNode; 
} 

void inorder(node* root) 
{ 
	if (root == NULL) 
		return; 
	inorder(root->left); 
	printf("%d ", root->val); 
	inorder(root->right); 
} 

void mirrorify(node* root, node** mirror) 
{ 
	if (root == NULL) { 
		mirror = NULL; 
		return; 
	} 
	*mirror = createNode(root->val); 
	mirrorify(root->left, &((*mirror)->right)); 
	mirrorify(root->right, &((*mirror)->left)); 
} 

int main(){
    int N;
    scanf("%d", &N);
    node* root = NULL;
    int val;
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        root = insertToBST(root, val);
    }
    node* mirror = NULL; 
    mirrorify(root, &mirror);
    inorder(mirror);
    return 0; 
} 
