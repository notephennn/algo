#include <stdio.h> 
#include <string.h> 

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N; 
    fscanf(file, "%d\n", &N); 

    int R[10000]; 
    char M[10000][45]; 

    for ( int i = 0; i < N; i++ ){
        fscanf(file, "%d#%[^\n]\n", &R[i], M[i]); 
    }

    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( strcmp(M[j], M[j+1]) > 0 ){
                // swapp nama
                char tempM[45]; // menyimpan variabel tempName ini di kanan 
                strcpy(tempM, M[j]); 
                strcpy(M[j], M[j+1]); 
                strcpy(M[j+1], tempM); 

                // swap nomor 
                int tempNumber = R[j]; // variabel buat nyimpen nomor yang ada di kiri 
                R[j] = R[j+1]; 
                R[j+1] = tempNumber; 

                tukar = 1;  
            }
        }

        if ( !tukar ) break; 
    }

    for ( int i = 0; i < N; i++ ){
        printf("%d %s\n", R[i], M[i]); 
    }

    fclose(file); 
}