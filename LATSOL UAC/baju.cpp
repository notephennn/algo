#include <stdio.h> 
#include <string.h> 

int size_to_chart(char size[]){
    if ( strcmp(size, "S") == 0 ) return 0; 
    if ( strcmp(size, "M") == 0 ) return 1; 
    if ( strcmp(size, "L") == 0 ) return 2; 
    if ( strcmp(size, "XL") == 0 ) return 3; 
    if ( strcmp(size, "XXL") == 0 ) return 4;
    return -1;  
}

int main(){
    int N; 
    scanf("%d", &N); 

    int interval_size[N][2]; 
    for ( int i = 0; i < N; i++ ){
        char S1[4], S2[2]; 
        scanf("%s %s", S1, S2); 
        interval_size[i][0] = size_to_chart(S1); 
        interval_size[i][1] = size_to_chart(S2); 
    }

    int used[5] = {0}; 
    int min_shirts = 0; 
    
    for ( int i = 0; i < N; i++ ){
        int found = 0; 
        for ( int size = interval_size[i][0]; size <= interval_size[i][1]; size++ ){
            if ( used[size]){
                found = 1; 
                break; 
            }
        }
        if ( !found ){
            min_shirts++; 
            for ( int size = interval_size[i][0]; size <= interval_size[i][1]; size++ ) used[size] = 1; 
        }
    }

    printf("%d\n", min_shirts); 
}