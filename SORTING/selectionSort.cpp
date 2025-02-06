#include <stdio.h> 
/*
    setiap iterasi, dia akan mencari nilai paling minimum
    7 1 4 3 9 
    iterasi 1 -> angka 7 
    sama kayak bubble, cmn minimumnya dari 7, diubah jd yg paling minimum   
*/

void selection_sort(int arr[], int size){
    int minimum = 0; 
    for ( int i = 0; i < size - 1; i++ ){
        minimum = i; 
        for ( int j = i + 1; j < size; j++ ){
            if ( arr[j] < arr[minimum] ){
                minimum = j; 
            }
        }
        // proses swap 
        int temp = arr[i]; 
        arr[i] = arr[minimum]; 
        arr[minimum] = temp; 
    }
}

void print_array(int arr[], int size){
    for ( int i = 0; i < size; i++ ){
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

int main(){
    int arr[] = {7, 1, 4, 3, 9}; 
    int size = sizeof(arr)/sizeof(int); // arr 4 x 5 / 4 

    print_array(arr, size); 
    selection_sort(arr, size); 
    print_array(arr, size); 
}   
