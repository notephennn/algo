#include <stdio.h> 

int jojonanci(long long X, long long Y, long long N){
    if (N == 0)
        return X;
    
    if (N == 1)
        return Y;

    return jojonanci(X, Y, N - 1) - jojonanci(X, Y, N - 2);
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int i = 0; i < T; i++ ){
        long long A, B, N; 
        scanf("%lld %lld %lld", &N, &A, &B); 

        long long result = jojonanci(A, B, N);

        printf("Case #%d: %lld\n", i+1, result);
    }
}