#include <stdio.h>
#include <string.h>  

void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp; 
}

void swapString(char a[], char b[]){
    char temp[105]; 
    strcpy(temp, a); 
    strcpy(a, b); 
    strcpy(b, temp); 
}

int partition(char nama[][105], int X[], int low, int high){
    int pivot_index = X[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if ( X[j] > pivot_index ){  
            i++; 
            swapInt(&X[i], &X[j]); 
            swapString(nama[i], nama[j]); 
        } else if (X[j] == pivot_index && strcmp(nama[j], nama[high]) < 0) { 
            i++;
            swapInt(&X[i], &X[j]);
            swapString(nama[i], nama[j]);
        }
    }

    swapInt(&X[i+1], &X[high]); 
    swapString(nama[i+1], nama[high]);

    return i+1; 
}

void quick_sort(char nama[][105], int X[], int low, int high ){
    if ( low < high ){
        int pi = partition(nama, X, low, high);     

        // Recursively sort the two halves
        quick_sort(nama, X, low, pi - 1); 
        quick_sort(nama, X, pi+1, high); 
    }
}

int main(){
    int T; 
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++){
        int N; 
        scanf("%d", &N); 

        char nama[N][105]; 
        int X[N]; 

        for (int i = 0; i < N; i++){
            scanf(" %[^#]#%d", nama[i], &X[i]); 
        }

        quick_sort(nama, X, 0, N - 1); 

        printf("Case #%d:\n", tc + 1); 
        for (int i = 0; i < N; i++){
            printf("%s - %d\n", nama[i], X[i]); 
        }
    }
}
