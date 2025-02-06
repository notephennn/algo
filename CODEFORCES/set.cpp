#include <stdio.h> 
/*
    8
    3 9 2
    4 9 1
    7 9 2
    2 10 2
    154 220 2
    147 294 2
    998 24435 3
    1 1000000000 2

    output: 
    2
    6
    0
    4
    0
    1
    7148
    500000000
*/

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int L, R, K; 
        scanf("%d %d %d", &L, &R, &K); 

        int operations = R / K - L + 1;

        printf("%d\n", operations > 0 ? operations : 0);
    }
}