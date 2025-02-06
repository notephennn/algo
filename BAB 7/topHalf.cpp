#include <stdio.h> 

void swap(int *x, int *y){
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int partition(int arr[], int start, int end){
    int pivot = arr[end]; 
    int i = start - 1; 

    for ( int j = start; j < end; j++ ){
        if ( arr[j] < pivot ){
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }

    swap(&arr[i+1], &arr[end]); 
    return i + 1; 
}

void quick_sort_recursion(int arr[], int start, int end){
    if ( start < end ){
        int pi = partition(arr, start, end); 

        quick_sort_recursion(arr, start, pi - 1); 
        quick_sort_recursion(arr, pi + 1, end); 
    }
}

int arr[100000] = {0};

int main(){
    int N; 
    scanf("%d", &N); 

    for ( int i = 0; i < N; i++ ){
        scanf("%d", &arr[i]); 
    }

    quick_sort_recursion(arr, 0, N - 1); 
    int mid = N / 2 + ( N % 2 == 0 ? 0 : 1); 

    for ( int i = mid; i < N; i++){
        if ( i == N - 1 ){
            printf("%d\n", arr[i]); 
        } else printf("%d ", arr[i]); 
    }
}