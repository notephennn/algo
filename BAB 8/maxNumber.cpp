#include <stdio.h> 

/*
    10 3
    5 3 4 2 5 3 5 1 2 2
    4 3 5
*/

int main(){
    int N, M; 
    scanf("%d %d", &N, &M); 

    int arr[105];

    for ( int i = 0; i < N; i++){
        scanf("%d", &arr[i]); 
    }

    int temp; 

    for ( int i = 0; i < M; i++ ){
        scanf("%d", &temp); 
        for ( int j = 0; j < N; j++){
            if ( arr[j] == temp ){
                arr[j] = -1; 
            }
        }
    }

    int max = arr[0]; 
    for ( int i = 1; i < N; i++ ){
        if ( arr[i] > max ) max = arr[i]; 
    }

    printf("Maximum number is %d\n", max); 
}