#include <stdio.h> 

/*
    2
    6
    1 6 9 7 2 3
    4
    2 2 1 1
*/

void bubble_sort(long long int A[], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++){
            if ( A[j] > A[j+1]){
                long long int temp = A[j]; 
                A[j] = A[j+1]; 
                A[j+1] = temp; 

                tukar = 1; 
            }
        }
        if ( !tukar ) break; 
    }
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        scanf("%d", &N); 

        long long int A[N]; 

        for ( int i = 0; i < N; i++ ){
            scanf("%lld", &A[i]); 
        }

        bubble_sort(A, N); 

        long long int maxDiff = 0; 
        int mid = N / 2; 

        for ( int i = 0; i < mid - 1; i++ ){
            long long int diff = A[i+1] - A[i]; 
            if ( diff > maxDiff) maxDiff = diff; // bagian maksimum di bagian pertama setelah disorting
        }

        for ( int i = mid; i < N - 1; i++ ){
            long long int diff = A[i+1] - A[i]; 
            if ( diff > maxDiff ) maxDiff = diff;
        }

        printf("Case #%d: %lld\n", tc+1, maxDiff); 
    }
}