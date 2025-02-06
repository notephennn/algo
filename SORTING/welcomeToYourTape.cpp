#include <stdio.h> 
#include <string.h> 
/*
    1
    16 8
    hannah
    clay
    zach
    tony
    justin
    tyler
    bryce
    jessica
    courtney
    alex
    jeff
    marcus
    monthy
    sheri
    skye
    ryan
*/

void swap(char *a, char *b){
    char temp[105];
    strcpy(temp, a); 
    strcpy(a, b); 
    strcpy(b, temp); 
}

int partition(char nama[][105], int low, int high){
    char *pivot = nama[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if(strcmp(nama[j], pivot) < 0){
            i++; 
            swap(nama[i], nama[j]); 
        }
    }

    swap(nama[i+1], nama[high]);  
    return i+1; 
}

void quick_sort_recursion(char nama[][105], int low, int high){
    if ( low < high ){
        int pi = partition(nama, low, high); 

        quick_sort_recursion(nama, low, pi-1);
        quick_sort_recursion(nama, pi+1, high);  
    }
}

int main(){
    int T; 
    scanf("%d\n", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int X, Y; 
        scanf("%d %d", &X, &Y); 
        
        char nama[X][105];  
        for ( int i = 0; i < X; i++ ){
            scanf(" %[^\n]", &nama[i]); getchar(); 
        }

        quick_sort_recursion(nama, 0, X - 1); 

        printf("%s\n", nama[Y-1]); 
    }
}