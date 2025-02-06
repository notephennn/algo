#include <stdio.h> 

long long transformasi(long long N){
    if ( N < 0 ) return N; 
    if ( N == 0 ) return 0; 
    if ( N % 2 == 0 ) return transformasi(N/2); 
    if ( N % 3 == 0 ) return transformasi(3*N/4);
    if ( N % 5 == 0 ) return transformasi(N - 500); 
    return transformasi(2*N / 3); 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        long long N; 
        scanf("%lld", &N); 

        long long result = transformasi(N); 
        printf("Case #%d: ", tc+1); 
        if ( result < 0 ) printf("Jojo Wins!\n"); 
        else printf("Lili Wins!\n"); 
    }

}