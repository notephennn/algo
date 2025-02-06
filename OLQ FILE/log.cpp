#include <stdio.h> 

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N; 
    fscanf(file, "%d\n", &N); 

    char tanah[N+5]; 
    fscanf(file, "%s", tanah); 

    int max = 0, current = 0; 

    for ( int i = 0; i < N; i++ ){
        if ( tanah[i] == '1'){
            current++; 
        } else {
            if ( current > max ){
                max = current; 
            }
            current = 0; 
        }
    }

    if ( current > max ){
        max = current; 
    }

    printf("%d\n", max); 

    fclose(file); 
}