#include <stdio.h> 

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int X, Y; 
    fscanf(file,"%d %d\n", &X, &Y); 

    printf("%d\n", X+Y); 

    fclose(file); 
}