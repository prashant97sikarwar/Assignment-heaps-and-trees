#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *left,*right;
};

int size = 0;
struct node *root = NULL;

struct node* getnode(int k) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node*));
	newnode->left = newnode->right = NULL;
	newnode->val = k;
	return newnode; 
}

int min(int a,int b) {
	if (a > b)
		return b;
	return a;
}

void swap(struct node* a,struct node* b) {
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}

struct node* insert(struct node *root,int k,int pow) {
	if (root == NULL || pow == -1) 
		return getnode(k);
		
	if ((size & (1 << pow)) == 0) {
		root->left = insert(root->left,k,pow-1);
	}
	else
		root->right = insert(root->right,k,pow-1);
		
	int mini = root->val;
	if (root->left != NULL)
		mini = min(mini,root->left->val);
		
	if (root->right != NULL)
		mini = min(mini,root->right->val);
	
	if (mini != root->val) {
		if (mini == root->left->val)
			swap(root,root->left);
		else
			swap(root,root->right);
	}
	
	return root; 
}

int find_msb_pow(int size) {
	int pow;
	for (pow=31; pow >= 0; pow--) {
		if (size & (1 << pow)) 
			return pow;
	}
	return 0;
}

void bfs() {
	struct node *queue[100];
	int head = 0,tail = 0;
	queue[tail++] = root;
	
	while (tail != head) {
		struct node *curr = queue[head];
		printf("%d ",curr->val);
		head++;
		
		if (curr->left != NULL)
			queue[tail++] = curr->left;		
		
		if (curr->right != NULL) 
			queue[tail++] = curr->right;
	}
	printf("\n");
}

struct node *delete_min(struct node *curr,int pow) {
	if (pow == -1) {
		root->val = curr->val;
		return NULL;
	}
	
	if ((size & (1 << pow)) == 0)
		curr->left = delete_min(curr->left,pow-1);
	else
		curr->right = delete_min(curr->right,pow-1);
}

void heapify(struct node *root) {
	if (root == NULL)
		return;
	
	int mini = root->val;
	if (root->left != NULL)
		mini = min(mini,root->left->val);
		
	if (root->right != NULL)
		mini = min(mini,root->right->val);
	
	if (mini != root->val) {
		if (mini == root->left->val) {
			swap(root,root->left);
			heapify(root->left);
		}
		else {
			swap(root,root->right);
			heapify(root->right);
		}
	}
}

int main () {
	int t;
	scanf("%d",&t);
	
	while (t--) {
		int option;
		scanf("%d",&option);
		
		if (option == 1) {
			int data;
			scanf("%d",&data);
			size++;
			int pow = find_msb_pow(size);
			pow--;
			root = insert(root,data,pow);
			bfs();
		}
		else if (option == 2) {
			int pow = find_msb_pow(size);
			pow--;
			root = delete_min(root,pow);
			heapify(root);
			if (root == NULL)
				printf("Empty\n");
			else
				bfs();
			size--;
		}
		else if (option == 3) {
			printf("False\n");
		}
		else if (option == 4) {
			if (root == NULL)
				printf("underflow\n");
			else
				printf("False\n");
		}
		else {
			printf("True\n");
			break;
		}
	}
}
