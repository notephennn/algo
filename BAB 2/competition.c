#include <stdio.h> 

int main() { 
    int X, Y; 

    int temp1, temp2, temp3, temp4;
    scanf("%d %d", &X, &Y);
    temp1 = X*Y;
    scanf("%d %d", &X, &Y);
    temp2 = X*Y;
    scanf("%d %d", &X, &Y);
    temp3 = X*Y;
    scanf("%d %d", &X, &Y);
    temp4 = X*Y;
    printf("%d\n", temp1);
    printf("%d\n", temp2);
    printf("%d\n", temp3);
    printf("%d\n", temp4);
}