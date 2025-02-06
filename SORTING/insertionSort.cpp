#include <stdio.h> 
/*
    sama kek bubble cuman dimulai dari belakang
*/

void insertion_sort(int arr[], int size){
    for ( int i = 1; i < size; i++ ){
        int current_index = arr[i]; 
        int j = i - 1; 
        while ( j >= 0 && arr[j] > current_index){
            arr[j+1] = arr[j]; 
            j--; 
        }
        arr[j+1] = current_index;
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
    insertion_sort(arr, size); 
    print_array(arr, size); 
}   