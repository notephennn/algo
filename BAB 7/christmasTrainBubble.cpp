#include <stdio.h> 
#include <stdbool.h> 

/*
    2
    5 2
    3 4 2 1 9
    4 3
    2 1 3 4
*/

int change; 

void swap(int *x, int *y){
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void bubble_sort_recursion(int arr[], int size, int *change){
    bool isSorted = true; 
    for ( int i = 0; i < size - 1; i++ ){
        if ( arr[i] > arr[i+1] ){
            swap(&arr[i], &arr[i+1]); 
            (*change)++; 
            isSorted = false; 
        }
    }

    if ( !isSorted ){
        bubble_sort_recursion(arr, size - 1, change); 
    }
}

int main(){
    int T; 
    scanf("%d", &T);
    
    for ( int tc = 0; tc < T; tc++ ){
        int N, X; 
        scanf("%d %d", &N, &X); 

        int arr[N]; 
        for ( int i = 0; i < N; i++) scanf("%d", &arr[i]); 

        int change = 0; 

        // bubble_sort_recursion(arr, N, &change);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N - i - 1; j++) {
                if (arr[i] > arr[j]) {
                    swap(&arr[i], &arr[j]);
                    change++;
                }
            }
        }

        printf("Case #%d: %d\n", tc+1, change * X); 
    }
}