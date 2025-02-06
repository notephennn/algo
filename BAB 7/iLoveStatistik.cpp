#include <stdio.h> 

/*
    2
    5
    3 1 2 5 4
    3
    1 9 11
*/

void bubble_sort(double A[], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++){
            if ( A[j] > A[j+1]){
                double temp = A[j]; 
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

        double A[N]; 
        double total = 0; 

        for ( int i = 0; i < N; i++ ){
            scanf("%lf", &A[i]); 
            total = total + A[i]; 
        }

        bubble_sort(A, N); 

        printf("Case #%d:\n", tc+1); 
        printf("Mean : %.2lf\n", total / N); 
        printf("Median : %.2lf\n", N % 2 == 0 ? (A[N/2 - 1] + A[N/2]) / 2    : A[N/2]); 
    }
}