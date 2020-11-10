int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        char k;
        scanf("%c%d", &k, &n);
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