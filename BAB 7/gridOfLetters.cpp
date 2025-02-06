#include <stdio.h> 
#include <string.h> 

/*
*/

int main(){
    int R, C; 
    scanf("%d %d", &R, &C); 
    getchar(); 

    char arr[R][C+1]; 

    for ( int i = 0; i < R; i++ ){
        scanf("%s", arr[i]); getchar(); 
    }

    for ( int i = 0; i < R; i++ ){
        int len = strlen(arr[i]);
        for ( int j = 0; j < len; j++){
            int tukar = 0; 
            for ( int k = 0; k < len - j - 1; k++ ){
                if ( arr[i][k] > arr[i][k+1]){
                    char temp = arr[i][k]; 
                    arr[i][k] = arr[i][k+1]; 
                    arr[i][k+1] = temp; 

                    tukar = 1; 
                }
            }
            if ( !tukar ) break; 
        }
    }

    for ( int i = 0; i < R; i++){
        int tukar = 0; 
        for ( int j = 0; j < R - i - 1; j++ ){
            if(strcmp(arr[j], arr[j+1]) < 0){
                char temp[C+1];
                strcpy(temp, arr[j]); 
                strcpy(arr[j], arr[j+1]); 
                strcpy(arr[j+1], temp); 

                tukar = 1; 
            }
        }
        if ( !tukar ) break; 
    }

    for ( int i = 0; i < R; i++){
        printf("%s\n", arr[i]); 
    }
}