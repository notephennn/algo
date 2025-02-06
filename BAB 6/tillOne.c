#include <stdio.h> 

int tillOne(int n){
    if ( n == 1 ){
        return 1; 
    } else if ( n % 2 == 0 ){
        return tillOne( n / 2 ); 
    } else {
        return tillOne(n-1) + tillOne(n+1); 
    }
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++){
        int X; 
        scanf("%d", &X); 

        printf("Case #%d: %d\n", tc+1, tillOne(X)); 
    }
}