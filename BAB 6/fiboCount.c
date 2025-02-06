#include <stdio.h> 

/*
    soalnya minta ngehitung count dari fibonacci 
*/

int fiboCount(int N){
    if ( N == 0){
        return 1; 
    }
    if ( N == 1 ){
        return 1; 
    }

    return 1 + fiboCount(N-1) + fiboCount(N-2);
}
int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int X; 
        scanf("%d", &X); 

        int hasil = fiboCount(X);

        printf("Case #%d: %d\n", tc+1, fiboCount(X));
    }
}