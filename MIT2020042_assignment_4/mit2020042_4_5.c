#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
   int  temp=*a;
    *a=*b;
    *b=temp;
}


void heapify(int arr[],int n,int i,int *count){
    int large = i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]>arr[large]){
        large = l;
    }
    if(r<n && arr[r]>arr[large]){
        large = r;
    }
    if(large!=i){
        swap(&arr[i],&arr[large]);
        (*count)++;
        heapify(arr,n,large,count);
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
     printf("\n");
}

void buildHeap(int arr[],int n){
    int si = n/2 -1;
    int count=0;
    for(int i=si;i>=0;i--)
        heapify(arr,n,i,&count);
        
    printf("%d\n",count);
}


int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
	    }
	    
	    buildHeap(arr,n);
	    printHeap(arr,n);
	}
	return 0;
}