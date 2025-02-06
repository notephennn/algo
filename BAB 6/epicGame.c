#include <stdio.h> 

/*
    Soal nya kalau genap dibagi dengan 2 kalau ganjil dikalikan dengan tiga ditambah dengan 1
*/

long long winner(long long N, int turn){
    // int turn = 0; // ini buat jojo, kl 1 buat lili 
    // while ( N != 1 ){
    //     if ( N % 2 == 0 ){
    //         N = N / 2; 
    //     } else {
    //         N = N * 3 + 1; 
    //     }
    //     turn = 1 - turn; // buat ganti giliran aja 
    // }
    // return turn; // kalau 0 brti lili yang terakhir bermain

    if ( N <= 1 ) return turn; 
    else if ( N % 2 == 0 ) return winner(N/2, 1-turn); 
    else return winner(N*3+1, 1-turn); 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        long long N; 
        scanf("%lld", &N); 

        int hasil = winner(N, 0); // 0 nandain awal gerakan buat lili 
        printf("Case #%d: ", tc+1);
        
        if ( hasil == 0 ){
            printf("Lili\n");
        } else {
            printf("Jojo\n"); 
        }
    }
}