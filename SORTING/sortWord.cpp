#include <stdio.h>
#include <string.h>

void swapString(char a[], char b[]){
    char temp[105]; 
    strcpy(temp, a); 
    strcpy(a, b); 
    strcpy(b, temp); 
}

int partition(char nama[][105], int low, int high, int X){
    char pivot[105];
    strcpy(pivot, nama[high]);  
    int i = low - 1; 

    for (int j = low; j < high; j++){
        if ( X == 0 ){
            if (strcmp(nama[j], pivot) < 0){
            i++;
            swapString(nama[i], nama[j]);  
            } 
        } else {
            if (strcmp(nama[j], pivot) > 0){
            i++;
            swapString(nama[i], nama[j]);  
            } 
        }  
    }

    swapString(nama[i + 1], nama[high]);  
    return i + 1;
}

void quick_sort(char nama[][105], int low, int high, int X){
    if (low < high){
        int pi = partition(nama, low, high, X);
        quick_sort(nama, low, pi - 1, X);  // Urutkan bagian kiri
        quick_sort(nama, pi + 1, high, X);  // Urutkan bagian kanan
    }
}

int main(){
    int N; 
    scanf("%d", &N);  

    char nama[N][105];  

    for (int i = 0; i < N; i++){
        scanf("%s", nama[i]); 
    }

    int x; 
    scanf("%d", &x); 

    quick_sort(nama, 0, N - 1, x); 

    for (int i = 0; i < N; i++){
        printf("%s\n", nama[i]); 
    }

    return 0;
}
