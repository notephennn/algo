#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        long long M; 
        scanf("%d %lld", &N, &M); 

        int A[N]; 
        for ( int i = 0; i < N; i++ ){
            scanf("%d", &A[i]); 
        }

        long long sub_array = 0; // fungsinya buat nyari sub nya yang gaboleh melebihi M 

        for ( int i = 0; i < N; i++ ){
            long long length = -1;  // menyimpan panjang segmen yang ada     
            long long bagian = 0;   // jumlah elem segmen yang ada 

            for ( int j = i; j < N; j++ ){
                if ( bagian + A[j] > M ) break; 
                if ( length == -1 ) length = 0; // mengatur length ketika dimulai ke 0 

                bagian = bagian + A[j];  // menambah nilai ke jumlah segmen 
                length++; // tambah panjang subArraynya 
            }

            if ( i == 0 || sub_array < length ){
                sub_array = length; 
            }
        }  
        printf("Case #%d: %lld\n", tc+1, sub_array); 
    }
}