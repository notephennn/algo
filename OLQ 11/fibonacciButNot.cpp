#include <stdio.h> 

int fibonacci(int N){
    if ( N <= 1 ) return N; 
    if ( N % 3 == 0 ) return 10; 
    return fibonacci(N-1) + fibonacci(N-2);  
}
    
int main(){
    int N; 
    scanf("%d", &N); 

    printf("%d", fibonacci(0)); 
    for ( int i = 1; i < N; i++ ){
        printf(" %d", fibonacci(i)); 
    }
    printf("\n"); 
}