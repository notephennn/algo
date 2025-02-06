#include <stdio.h>

int main(){
    int X, Y, K;

    scanf("%d %d %d", &X, &Y, &K);

        if (K-X == Y-K && (K-X)>= 0)
        {
            printf("%d\n", K-X);
        } else {
            printf("-1\n");
        }
    
    return 0;
}