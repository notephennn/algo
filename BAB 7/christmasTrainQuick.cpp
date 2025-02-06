#include <stdio.h>

/*
    2
    5 2
    3 4 1 2 9 
    4 3
    2 1 3 4 
*/

int counter;

void swap(int *A, int *B) {
    int temp = *A; 
    *A = *B; 
    *B = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1; 
}

void quick_sort_recursion(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        // Panggil rekursif untuk bagian yang dihasilkan
        quick_sort_recursion(arr, low, pi - 1); 
        quick_sort_recursion(arr, pi + 1, high);

        counter++; 
    }
}

int main() {
    int T; 
    scanf("%d", &T);  

    for (int tc = 0; tc < T; tc++) {
        int N, X; // jumlah gerbong, waktu untuk swap
        scanf("%d %d", &N, &X); 

        int A[10000]; 
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]); 
        }

        counter = 0; 

        quick_sort_recursion(A, 0, N - 1); 

        printf("Case #%d: %d %d\n", tc + 1, counter, counter * X); 
    }

    return 0;
}
