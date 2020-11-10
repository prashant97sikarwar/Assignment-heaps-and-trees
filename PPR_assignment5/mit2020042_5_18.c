//deletion from a binary search tree;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root=NULL;

void inorderTraversal(struct Node* root)
{
    if(root==NULL)
    return;
    else
    {
      inorderTraversal(root->left);
      printf(" %d ",root->data);
      inorderTraversal(root->right);
    }
    
}

int clear(struct Node* root,struct Node* root1)
{
    struct Node* temp;
    if(root==NULL)
    return 0;
    if(root->left==root1)
     {  // free(root->left);
         root->left=NULL;
         return 1;

     }
     else  if(root->right==root1)
      {
         // free(root->right);
          root->right=NULL;
          return 1;
      }
      else
      {
         return (clear(root->left,root1)|| clear(root->right,root1));
      }
      
}
struct Node* delete(struct Node * root,struct Node* root1)
{  struct Node * temp;
   if(root1->left==NULL&&root1->right==NULL)
    {clear(root,root1);
    return NULL;}
   else  if(root1->right==NULL)
    {  temp=root1->left;
       while(temp->right!=NULL)
       {
           temp=temp->right;
       }
       root1->data=temp->data;
       clear(root,temp);
       return root1;

   }

  else 
     {
      temp=root1->right;
      while(temp->left!=NULL)
      {
          temp=temp->left;
      }
      root1->data=temp->data;
      clear(root,temp);
     return root1;
     }


}
void duplicate(struct Node* root1, int data)  //code to delete duplicates
{  if(root1==NULL)
    return;
    if(root1->data==data)
    {root1=delete(root,root1);
     duplicate(root1,data);
    }
    else
    {
         duplicate(root1->left,data);
    }
    
}
void deleteDuplicate_bst(struct Node* root)
{
     if(root==NULL)
     return ;
     else

     {   
         duplicate(root->right,root->data);
         deleteDuplicate_bst(root->left);
         deleteDuplicate_bst(root->right);
     }
     

}
struct Node* insertBinarySearchTree(struct Node* root,int data)
{
    if(root==NULL)
     { root=(struct Node*)malloc(sizeof(struct Node));
       root->data=data;
       root->left=NULL;
       root->right=NULL;
       return root;

      }

      else if(root->data>data)
         {
             root->left=insertBinarySearchTree(root->left,data);
             return root;
         }
         else
         {
             root->right=insertBinarySearchTree(root->right,data);
              return root;

         }

    }

int searchBinary(struct Node* root,int data)
{
  if(root==NULL)
  return 0;
  else if(root->data==data)
  return 1;
  else if(root->data>data)
      return(searchBinary(root->left,data));
      else
       return(searchBinary(root->right,data));
         
}

int main()
{
 int element_Btree;
 scanf("%d",&element_Btree);
 int i;
 int element;
 int num;
 //creating binary tree
 for (i=0;i<element_Btree;i++)
 {
     scanf("%d",&num);
     root=insertBinarySearchTree(root,num);
 }

inorderTraversal(root);
printf("\nafter remoaval of duplicates:\n");
deleteDuplicate_bst(root);
inorderTraversal(root);
}