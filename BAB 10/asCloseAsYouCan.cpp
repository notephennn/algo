#include <stdio.h> 
/*
    4
    3 2 7 6
    3
    8
    20
    12 -> 2 4 3
    5
    2 9 5 5 7
    6
    11
    12
    16
    17
    22
    3 -> 2 2 3 3 4 1
*/

int binary_search(long long prefix_sum[], int N, long long M){
    int left = 0; 
    int right = N - 1; 
    int result = -1; 

    while ( left <= right ){
        int middle = left + ( right - left ) / 2; 
        if ( prefix_sum[middle] <= M ){
            result = middle; 
            left = middle + 1; 
        } else {
            right = middle - 1; 
        }
    }

    return result; 
}

int main(){
    int N; 
    scanf("%d", &N); 

    int A[N]; 
    for ( int i = 0; i < N; i++ ){
        scanf("%d", &A[i]); 
    }

    long long prefix_sum[N];
    prefix_sum[0] = A[0];

    for ( int i = 1; i < N; i++ ){
        prefix_sum[i] = prefix_sum[i-1] + A[i]; 
    }

    long long Q; 
    scanf("%lld", &Q); 

    long long arr[Q]; 
    for ( int i = 0; i < Q; i++ ){
        scanf("%lld", &arr[i]); 

        int index = binary_search(prefix_sum, N, arr[i]); 

        printf("Case #%d: ", i+1); 
        if ( index != -1 ){
            printf("%d\n", index+1); 
        } else {
            printf("-1\n"); 
        }
    }   
}