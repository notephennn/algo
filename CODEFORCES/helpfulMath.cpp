#include <stdio.h> 

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int low, int high){
    int pivot_index = arr[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if ( arr[j] < pivot_index){
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }

    swap(&arr[i+1], &arr[high]); 
    return i + 1; 
}

void quick_sort_recursion(int arr[], int low, int high){
    if ( low < high ){
        int pi = partition(arr, low, high); 
        quick_sort_recursion(arr, low, pi - 1); 
        quick_sort_recursion(arr, pi+1, high); 
    }
}

int main(){
    char S[105]; 
    scanf("%s", S); 

    int number[101];
    int n = 0; 
    int num = 0; 

    for ( int i = 0; S[i] != '\0'; i++ ){
        if ( S[i] == '+') {
            number[n++] = num; 
            num = 0; 
        } else num = num * 10 + ( S[i] - '0'); 
    }

    number[n++] = num; 

    quick_sort_recursion(number, 0, n-1); 

    for ( int i = 0; i < n; i++ ){
        if ( i > 0 ) printf("+"); 
        else printf("%d", number[i]); 
    }
    printf("\n"); 
}