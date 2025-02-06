#include <stdio.h> 

int fibo(int N, int X, int Y){
    if ( N == 0 ){
        return X; // ini untuk kasus f0
    }
    if ( N == 1 ){
        return Y; // untuk kasus f1
    }

    int a = X; int b = Y; int c; 
    for ( int i = 2; i <= N; i++ ){
        c = a + b; // jadi dia menghasilkan fn dari f1 + f0
        a = b; // update fn-1
        b = c; // update fn nya
    }
    return b; // fn yang dihasilkan 
}

int main(){
    int X, Y; // f0 dan f1
    scanf("%d %d", &X, &Y); 

    int K; 
    scanf("%d", &K); 

    int hasil = fibo(K, X, Y); 
    printf("%d\n", hasil); 
}