#include <stdio.h>
#include <malloc.h>
#include <limits.h>

void heapify(int *heap, int i, int n){
    while(i != n){
        int left = i * 2;
        int right = 2 * i + 1;
        int min = i;
        if(left <= n && heap[left] < heap[i]){
            min = left;
        }

        if(right <= n && heap[right] < heap[min]){
            min = right;
        }

        if(min == i) return;

        int temp = heap[min];
        heap[min] = heap[i];
        heap[i] = temp;

        heapify(heap, min, n);
    }
}


int* construct_heap(int* arr, int n){
    int* heap = (int*)malloc(sizeof(int)*(n + 1));
    heap[0] = INT_MIN;
    for (int i = 1; i <= n; i++){
        heap[i] = arr[i - 1];
    }

    for (int i = n / 2; i >= 1; i--){
        heapify(heap, i, n);
    }
    return heap;
}

int delete_min(int *heap, int size){
    int val = heap[1];
    heap[1] = heap[size];
    heapify(heap, 1, size - 1);
    return val;
}

void print(int *heap, int n){
    for (int i = 1; i <= n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        int *arr = (int *) malloc (sizeof(int) * n);
        for (int i = 0; i < n; i++){
            scanf("%d", (arr + i));
        }

        int* heap = construct_heap(arr, n);
        int heap_size = n;

        for (int i = 0; i < k; i++){
            delete_min(heap, heap_size);
            heap_size--;
        }

        print(heap, heap_size);
    }
    return 0;
}