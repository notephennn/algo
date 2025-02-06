#include <stdio.h> 
/*
    1
    2 -> 2
    1
    10 -> 3
*/

long long rumus(long long N){ // ini untuk menghindari overflow yang ada 
    return (long long) N * ( N + 1 ) * ( 2 * N + 1 ) / 6; // rumus menghitung 1^2 + ... + N^2
}

int find_minimum(long long M){
    int result = -1;        
    int low = 1;            // karena dimulai dari N^2 nya kan 1 
    int high = 10000000;      // ini kayaknya cukup deh sgini

    while ( low <= high ){
        int middle = low + ( high - low ) / 2; 
        long long sum_sekarang = rumus(middle);

        if ( sum_sekarang >= M ){
            result = middle; // simpan sementara hasilnya 
            high = middle - 1; // cari N yang lebih mempersempit rentang yang ada 
        } else {
            low = middle + 1; // klau < M makapencarian selalu dilakukan ke sebelah kanan 
        }
    }

    return result; 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        long long M; 
        scanf("%lld", &M); 

        long long result = find_minimum(M); 

        printf("Case #%d: %lld\n", tc+1, result); 
    }
}