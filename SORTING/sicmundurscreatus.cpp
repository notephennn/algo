#include <stdio.h> 

/*
    2
    3
    2019
    1986
    1953
    7
    1945
    2020
    2055
    1919
    2013
    1975
    2000
*/

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if ( arr[j] <= pivot ){
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }

    swap(&arr[i+1], &arr[high]); 
    return i  + 1; 
}

void quick_sort_recursion(int arr[], int low, int high){
    if ( low < high ){
        int pi = partition(arr, low, high); 

        quick_sort_recursion(arr, low, pi - 1); 
        quick_sort_recursion(arr, pi + 1, high); 
    }
}

int main(){
    int T; 
    scanf("%d\n", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        scanf("%d\n", &N); 

        int years[N]; 
        for ( int i = 0; i < N; i++ ){
            scanf("%d", &years[i]); 
        }

        quick_sort_recursion(years, 0, N - 1); 

        int min_diff = years[1] - years[0]; 

        for ( int i = 1; i < N-1; i++ ){
            int diff = years[i+1] - years[i]; 

            if ( min_diff > diff ){
                min_diff = diff; 
            }
        }

        printf("Case: %d\n", min_diff); 
    }
}