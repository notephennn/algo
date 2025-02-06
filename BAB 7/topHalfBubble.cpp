#include <stdio.h> 

int main(){
    int N; 
    scanf("%d", &N); 

    int A[N]; 
    for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]); 

    for ( int i = 0; i < N - 1; i++ ){
        int swapped = 0; 
        for ( int j = i + 1; j < N; j++ ){
            if ( A[i] > A[j]){
                int temp = A[i]; 
                A[i] = A[j]; 
                A[j] = temp; 

                swapped = 1; 
            }
        }
        if ( !swapped ) break; 
    }

    for ( int i = N / 2 + 1; i < N; i++ ){
        if ( i == N - 1 ){
            printf("%d\n", A[i]); 
        } else printf("%d ", A[i]); 
    }
}