#include<stdlib.h>
#include<stdio.h>
#define println() printf("\n")

int H[50]; 
int size = -1; 
  
int parent(int i) 
{ 
  
    return (i - 1) / 2; 
} 
  
int leftChild(int i) 
{ 
  return ((2 * i) + 1); 
} 
  
int rightChild(int i) 
{ 
  
    return ((2 * i) + 2); 
} 
  
void shiftUp(int i) 
{ 
    while (i > 0 && H[parent(i)] < H[i]) { 
        int temp = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = temp;
  
        i = parent(i); 
    } 
} 

void insert(int p) 
{ 
    size = size + 1; 
    H[size] = p; 
    shiftUp(size); 
} 

int main(){
    int n;
    scanf("%d",&n);
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        insert(num);
    }
    int i = 0; 
    while (i <= size) { 
        printf("%d ",H[i]);
        i++; 
    }
    println();
}