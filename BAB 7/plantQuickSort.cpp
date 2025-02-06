#include <stdio.h> 
#include <string.h> 

typedef struct{
    int nomor; 
    char nama[40+5]; 
} tanaman; 

void swap(tanaman *a, tanaman*b){
    tanaman temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(tanaman daftarTanaman[], int low, int high){
    tanaman pivot = daftarTanaman[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if ( strcmp(daftarTanaman[j].nama, pivot.nama) < 0 ){
            i++; 
            swap(&daftarTanaman[i], &daftarTanaman[j]); 
        }
    }

    swap(&daftarTanaman[i+1], &daftarTanaman[high]); 
    return i+1; 
}

void quick_sort_recursion(tanaman daftarTanaman[], int low, int high){
    if ( low < high ){
        int pivot = partition(daftarTanaman, low, high); 

        quick_sort_recursion(daftarTanaman, low, pivot - 1); 
        quick_sort_recursion(daftarTanaman, pivot+1, high); 
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int T; 
    fscanf(file, "%d\n", &T); 

    tanaman daftarTanaman[T]; 
    for ( int i = 0; i < T; i++ ){
        fscanf(file, "%d#%[^\n]\n", &daftarTanaman[i].nomor, &daftarTanaman[i].nama); 
    }

    quick_sort_recursion(daftarTanaman, 0, T - 1); 

    for ( int i = 0; i < T; i++ ){
        printf("%d %s\n", daftarTanaman[i].nomor, daftarTanaman[i].nama); 
    }

    fclose(file); 
}