#include <stdio.h> 
/*
    3
    1
    69
    3
    7 6 5
    5
    1 1 1 2 2

    output : 
    0
    4
    4
*/

int bubble_sort_recursion(int arr[], int N){
    for ( int i = 0; i < N - 1; i++ ){
        int swapped = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( arr[j] > arr[j+1]){
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 

                swapped = 1; 
            }
        }
        if ( !swapped ) break; 
    }
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        scanf("%d", &N); 

        int A[N];
        for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]); 

        bubble_sort_recursion(A, N); 

        int minVal = A[0]; 
        int maxVal = A[0]; 
        long long int score = 0; 
        
        for ( int i = 0; i < N; i++ ){
            if ( A[i] < minVal ) minVal = A[i]; 
            if ( A[i] > maxVal ) maxVal = A[i]; 

            score = score + (maxVal - minVal); 
        }

        printf("%lld\n", score); 
    }
}