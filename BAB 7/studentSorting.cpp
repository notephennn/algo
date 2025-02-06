#include <stdio.h> 
#include <string.h>

/*
    10 
    2020123464 Oliver 
    2020123461 Benjamin 
    2020123458 William 
    2020123460 Logan 
    2020123457 Noah 
    2020123462 Mason 
    2020123456 Liam 
    2020123459 James 
    2020123463 Elijah 
    2020123465 Jacob
*/

void bubble_sort(char identifikasi[][11], char nama[][25], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( strcmp(identifikasi[j], identifikasi[j+1]) > 0 ){
                char tempId[11]; 
                strcpy(tempId, identifikasi[j]); 
                strcpy(identifikasi[j], identifikasi[j+1]); 
                strcpy(identifikasi[j+1], tempId);

                char tempNama[25]; 
                strcpy(tempNama, nama[j]); 
                strcpy(nama[j], nama[j+1]); 
                strcpy(nama[j+1], tempNama); 

                tukar = 1; 
            }
        }
        if ( !tukar ) break; 
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N;  
    fscanf(file, "%d\n", &N); 

    char identifikasi[N][11]; 
    char nama[N][25]; 

    for ( int i = 0; i < N; i++ ){
        fscanf(file, "%s %s\n", identifikasi[i], nama[i]); 
    }

    bubble_sort(identifikasi, nama, N); 

    for ( int i = 0; i < N; i++ ){
        printf("%s %s\n", identifikasi[i], nama[i]);
    }

    fclose(file); 
}