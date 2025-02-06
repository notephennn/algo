#include <stdio.h> 

int ackerman(int m, int n){
    if ( m == 0 ){
        return n + 1; 
    }
    
    if ( m > 0 && n == 0){
        return ackerman(m-1, 1);
    }

    return ackerman(m-1, ackerman(m, n-1));
}

int main(){
    int X, Y; 
    scanf("%d %d", &X, &Y); 

    printf("result: %d\n", ackerman(X,Y));
}