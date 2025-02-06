#include <stdio.h> 

int jobonacci(int N){
    if ( N == 0 ) return 0; 
    if ( N == 1 ) return 1;

    if ( N % 2 != 0 ) return 1; 
    else return jobonacci(N-1) + jobonacci(N-2); 
}

int main(){
    int X; 
    scanf("%d", &X); 

    int hasil = jobonacci(X); 
    printf("%d\n", hasil); 
}