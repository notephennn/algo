#include <stdio.h> 
#include <math.h> 

/*
    5
    2 -8 3 1 -10

    10
    45 9 3 -6 100 68 -57 23 -11 -25
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
    for ( int i = 0; i < N; i++ ) scanf("%lld", &A[i]); 

    quick_sort_recursion(A, 0, N-1); 

    long long int maxSelisih = 0; 
    long long selisih[200005] = {0}; 
    for ( int i = 0; i < N-1; i++ ){
        selisih[i] = abs(A[i] - A[i+1]); 
        if ( selisih[i] > maxSelisih ) maxSelisih = selisih[i]; 
    }

    int flag = 1; 
    for ( int i = 0; i < N-1; i++ ){
        if ( selisih[i] == maxSelisih ){
            if ( !flag ) printf(" "); 
            printf("%lld %lld", A[i], A[i+1]); 
            flag = 0; 
        }
    }

    printf("\n"); 
}