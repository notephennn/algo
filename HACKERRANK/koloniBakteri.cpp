#include <stdio.h>
#define MOD 1000000000 
/*
    2
    4 9
    8 7
*/
long long int memo[1001][1001]; 

long long int F(int N, int K){
    if ( N <= 1 ) return 1; 

    if ( memo[N][K] != -1 ) return memo[N][K]; 

    if ( K == 1 ) return memo[N][K] = N; 

    long long int result = (N * F(N, K - 1) % MOD + F(N - 1, K) % MOD) % MOD;
    memo[N][K] = result;

    return result; 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int i = 0; i <= 1000; i++ ){
        for ( int j = 0; j <= 1000; j++ ){
            memo[i][j] = -1; 
        }
    }

    for ( int tc = 0; tc < T; tc++ ){
        int N, K; 
        scanf("%d %d", &N, &K); 

        long long int result = F(N, K); 
        printf("Case #%d: %lld\n", tc+1, result); 
    }
}