#include <stdio.h> 
#include <string.h> 

typedef struct{
    char nim[40]; 
    char nama[40]; 
} student; 

void swap(student *a, student *b){
    student temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(student daftarStudent[], int low, int high){
    student pivot = daftarStudent[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if(strcmp(daftarStudent[j].nim, pivot.nim) <= 0){
            i++; 
            swap(&daftarStudent[i], &daftarStudent[j]); 
        }
    }

    swap(&daftarStudent[i+1], &daftarStudent[high]); 
    return i + 1; 
}   

void quick_sort_recursion(student daftarStudent[], int low, int high){
    if ( low < high ){
        int pivot = partition(daftarStudent, low, high); 

        quick_sort_recursion(daftarStudent, low, pivot - 1); 
        quick_sort_recursion(daftarStudent, pivot + 1, high);  
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int T; 
    fscanf(file, "%d\n", &T); 

    student daftarStudent[T]; 

    for ( int i = 0; i < T; i++ ){
        fscanf(file, "%s %[^\n]\n", daftarStudent[i].nim, daftarStudent[i].nama); 
    }

    quick_sort_recursion(daftarStudent, 0, T-1); 

    for ( int i = 0; i < T; i++ ){
        printf("%s %s\n", daftarStudent[i].nim, daftarStudent[i].nama); 
    }

    fclose(file); 
}