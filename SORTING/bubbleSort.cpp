#include <stdio.h> 
/*
    Sorting Ascending ( terkecil -> terbesar )
    7 1 4 3 9 
    7 > 1 ? -> True ( Iteration 1 )
    1 7 4 3 9 
    7 > 4 -> true ( iteration 2 )
    1 4 7 3 9 
    7 > 3 -> true ( iteration 3 )
    1 4 3 7 9 
    4 > 3 -> true ( iteration 4 )
    1 3 4 7 9  
*/

void print_array(int arr[], int size){
    for ( int i = 0; i < size; i++ ){
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

void bubble_sort(int arr[], int size){
    for ( int i = 0; i < size; i++ ){
        int swapped = 0; 
        for ( int j = 0; j < size - i - 1; j++ ){
            if ( arr[j] > arr[j+1] ){
                // proses swap 
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 

                swapped = 1; 
            }
        }
        if ( !swapped ) break; 
    }
}

int main(){
    int arr[] = {7, 1, 4, 3, 9}; 
    int size = sizeof(arr)/sizeof(int); // arr 4 x 5 / 4 

    print_array(arr, size); 
    bubble_sort(arr, size); 
    print_array(arr, size); 
}