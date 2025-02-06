#include <stdio.h> 
/*
    Quick Sort Algorithms Geeks For Geeks 
*/

void swap( long long int *a, long long int *b ){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}


int partition(long long int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = ( low - 1 ); 

    for ( int j = low; j < high; j++ ){
        if ( arr[j] <= pivot ){
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i+1], &arr[high]); 
    return( i + 1); 
}

void quick_sort_recursion(long long int arr[], int low, int high ){
    if ( low < high ){
        int pi = partition(arr, low, high); 

        quick_sort_recursion(arr, low, pi - 1); 
        quick_sort_recursion(arr, pi + 1,  high); 
    }
}

int main(){
    int N; 
    scanf("%d", &N); 

    long long int A[N]; 
    for ( int i = 0; i < N; i++ ){
        scanf("%lld", &A[i]); 
    }

    quick_sort_recursion(A, 0, N-1); 

    for ( int i = 0; i < N; i++ ){
        printf("%lld ", A[i]); 
    }
}