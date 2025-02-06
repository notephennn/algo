#include <stdio.h> 
#include <string.h>

/*
    1
    JOJO
    2
    J L
    O I
*/

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int T; 
    fscanf(file, "%d\n", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        char X[105]; 
        fscanf(file, "%[^\n]\n", X); 

        int len = strlen(X);    
        int tidakBerulang[26] = {0}; // untuk menghindari perubahan secara berulang 

        int N; 
        fscanf(file, "%d\n", &N); 

        for ( int i = 0; i < N; i++ ){
            char awal, akhir; 
            fscanf(file, "%c %c\n", &awal, &akhir); 

            for ( int j = 0; j < len; j++){
                if ( X[j] == awal && tidakBerulang[awal - 'A'] == 0) X[j] = akhir; 
            }

            tidakBerulang[awal - 'A'] = 1; 
        }

        int terjadi[26] = {0}; 

        for ( int i  = 0; i < len; i++ ){
            terjadi[X[i] - 'A']++; // misal X[i] nya A - A = 0, makanya diplus dengan satu untuk menghitung kemunculan nya 
        }
        
        for ( int i = 0; i <= 25; i++ ){
            if ( terjadi[i] == 0 ) continue; 
            printf("%c %d\n", i+'A', terjadi[i]); 
        }
    }

    fclose(file); 
}