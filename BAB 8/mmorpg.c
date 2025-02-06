#include <stdio.h> 

/*
    5
    1 2 3 4 5
    15 -> 5

    3
    69 69 420 
    361 -> 2
*/

void bubble_sort(long long int arr[], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( arr[j] > arr[j+1]){
                long long int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 

                tukar = 1; 
            }
        }

        if ( !tukar ) break; 
    }
}

long long int solve(long long int arr[], int N, long long int Y){
    bubble_sort(arr, N); 

    long long int count = 0; 

    for ( int i = 0; i < N; i++){
        long long int P = arr[i]; 

        if ( Y >= P){
            Y = Y - P; 
            count++; 
        }
    }

    return count; 
}

int main(){
    int N; 
    scanf("%d", &N); 

    long long int arr[N]; 

    for ( int i = 0; i < N; i++ ){
        scanf("%lld", &arr[i]); 
    }

    long long int Y; 
    scanf("%lld", &Y); 

    long long int result = solve(arr, N, Y); 

    printf("%lld\n", result); 
}