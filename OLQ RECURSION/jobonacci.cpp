#include <stdio.h> 

int jobonacci(int N){
    if ( N == 0 ) 
        return 0;
    if ( N == 1 ) 
        return 1; 
    if ( N == 2 ) 
        return 1; 

    return jobonacci(N-1) + jobonacci(N-3);  
}

int main(){
    int N; 
    scanf("%d", &N); 

    printf("%d\n", jobonacci(N)); 
}