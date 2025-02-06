#include <stdio.h> 

long long transformasi(long long N, long long count){ 
    if ( N % 3 == 0 ) count++; 
    if ( N <= 2 ) {
        return count;   
    }
    if ( N % 2 == 0 && N % 4 == 0 ) {
        return transformasi((N * 3 / 4 ), count); 
    }
    if ( N % 2 != 0 && N % 3 == 0 ) {
        return transformasi(N - 3, count); 
    }
    else if ( N % 2 == 0 && N % 4 != 0 ) {
        return transformasi(N - 1, count); 
    }

    return transformasi(N - 2, count); 
}

int main(){
    int T; 
    scanf("%d", &T);        

    for ( int tc = 0; tc < T; tc++ ){
        long long N; 
        scanf("%lld", &N); 

        long long result = transformasi(N, 0); 
        printf("Case #%d: %lld\n", tc+1, result); 
    }
}