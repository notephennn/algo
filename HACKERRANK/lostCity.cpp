#include <stdio.h> 
/*
    2
    15
    37 14 13 12 20 10 36 5 25 19 9 31 16 17 11
    19
    7
    17 9 15 39 21 34 8
    28

    Output : 
    3
    -1
*/

int findKedalaman(int arr[], int N, int Q){
    for ( int i = 0; i < N; i++ ){
        if ( arr[i] == Q ) { // mencari indeks Q dalam array i, terus ngecek dia ada di indeks berapa 
            int kedalaman = 0; 
            while( i > 0 ) {
                i = ( i - 1 ) / 2; // mencari rootnya ada di indeks berapa, buat ngecek kedalamannya 
                kedalaman++; 
            }

            return kedalaman; 
        }
    }

    return -1; 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        scanf("%d", &N); 

        int A[N]; 
        for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]); 

        int Q; 
        scanf("%d", &Q); 

        int result = findKedalaman(A, N, Q); 

        printf("Case #%d: %d\n", tc+1, result); 
    }
}