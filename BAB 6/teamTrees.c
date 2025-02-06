#include <stdio.h> 

/*
    disoal diminta fungsi untuk arrayya dan ditotal     
*/

int totalPohon(int A[100005], int N){
    if ( N < 1 ){ // dia hrus kurang dari 1 jadi langsung aja return 0 
        return 0; // ya kalau gaada hari lagi       
    }

    return A[N-1] + totalPohon(A, N-1); // tambahkan aja total phon pada hari ke N dengan hari hari sebelumnya
} // 4 + 

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int X; 
        scanf("%d", &X); 

        int A[X]; // menyimpan arraynya 
        
        for ( int i = 0; i < X; i++ ){
            scanf("%d", &A[i]); 
        } // 1 2 3 4 4

        int total = totalPohon(A, X); // manggil fungsi rekursinya 

        printf("Case #%d: %d\n", tc+1, total); 
    }
}