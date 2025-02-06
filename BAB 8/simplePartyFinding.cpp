#include <stdio.h> 

/*
    3
    10
    3246 4255 4873 5004 5095 6001 6692 7100 7610 9712 
    9712
    8
    4957 5444 5464 5634 6149 6622 8313 9492 
    4957
    6
    5393 6021 7233 8115 8118 9304
    9999
*/

void buble_sort(int arr[], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( arr[j] > arr[j+1]){
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 

                tukar = 1; 
            }
        }

        if ( !tukar ) break; 
    }
}

int main(){
    int K; 
    scanf("%d", &K); 

    for ( int i = 0; i < K; i++ ){
        int N; 
        scanf("%d", &N); 

        int A[N]; 

        for ( int j = 0; j < N; j++ ){
            scanf("%d", &A[j]); 
        }

        buble_sort(A, N); 

        int F; 
        scanf("%d", &F); 

        int index = -1; 
        for ( int j = 0; j < N; j++ ){
            if ( A[j] == F ) {
                index = j; 
                break; 
            } 
        }

        printf("CASE #%d: ", i+1); 

        if ( index == -1 ){
            printf("%d %d\n", -1, -1); 
        } else if ( index == 0 ){
            printf("%d %d\n", A[index], A[index+1]); 
        } else if ( index == N - 1 ){
            printf("%d %d\n", A[index - 1], A[index]);    
        } else {
            printf("%d %d\n", A[index], A[index+1]); 
        }
    }
}