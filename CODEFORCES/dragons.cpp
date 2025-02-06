#include <stdio.h> 
/*
    2 2
    1 99 
    100 0
*/

void bubble_sort_recursion(int dragons[][2], int N){
    for ( int i = 0; i < N - 1; i++ ){
        int swapped = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( dragons[j][0] > dragons[j+1][0]){
                int temp1 = dragons[j][0]; 
                int temp2 = dragons[j][1]; 
                dragons[j][0] = dragons[j+1][0]; 
                dragons[j][1] = dragons[j+1][1]; 
                dragons[j+1][0] = temp1; 
                dragons[j+1][1] = temp2; 

                swapped = 1; 
            }
        }
        if ( !swapped ) break; 
    }
}

int main(){
    int S, N; 
    scanf("%d %d", &S, &N); 

    int dragons[N][2]; 
    for ( int i = 0; i < N; i++ ) scanf("%d %d", &dragons[i][0], &dragons[i][1]); 

    bubble_sort_recursion(dragons, N); 

    for ( int i = 0; i < N; i++ ){
        if ( S > dragons[i][0]) S = S + dragons[i][1]; 
        else {
            printf("NO\n"); 
            return 0; 
        }
    }

    printf("YES\n"); 
}