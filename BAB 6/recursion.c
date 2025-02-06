#include <stdio.h> 

/*
    disoal minta output berapa yang ada pada fn dan kelipatan 3 nya ada berapa 
*/

int kelipatan = 0; // fungsinya mempertahankan nilai kelipatan 3 yang ada dalam proses rekursi, jadi ga sekali jalan aja 

int fun( int N ){
    if ( N % 3 == 0 && N != 0 ) {
        kelipatan++; // dia mau menghitung kelipatan 3 tanpa menganggap 0 benar 
    } 
    if ( N == 1 ){
        return 2; // tertera pada soal
    } else if ( N == 0 ){
        return 1; // tertera pada soal
    } else if ( N % 5 == 0 ){
        return N * 2; // tertera pada soal
    } else return fun( N - 1 ) + N + fun( N - 2 ) + N-2; 
}
int main(){
    int T; 
    scanf("%d", &T); 

    for ( int i = 0; i < T; i++){
        int X; 
        scanf("%d", &X); 

        kelipatan = 0; // kita perlu untuk reset kelipatan ke 0 pada setiap case

        printf("Case #%d: %d ", i+1, fun(X));
        printf("%d\n", kelipatan);  
    }
}