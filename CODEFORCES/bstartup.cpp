#include <stdio.h> 
#include <stdlib.h> 
#define MAX_BRAND 1000
#define MAX_JUMLAH 200000
/*
    soalnya ada rak, dan banyak botol, nah dia tuh disuruh buat ngumpulin botol dengan harga tertinggi untuk ditampilkan dalam rak 
    Input : 
    4
    3 3
    2 6
    2 7
    1 15
    1 3
    2 6
    2 7
    1 15
    6 2
    1 7
    2 5
    190000 1
    1 1000

    Output: 
    28
    15
    12
    1000
*/

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int low, int high){
    int pivot_index = arr[high]; 
    int i = low - 1; 

    for ( int j = low; j < high; j++ ){
        if ( arr[j] >= pivot_index ){
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

        quick_sort_recursion(arr, low, pi-1); 
        quick_sort_recursion(arr, pi+1, high); 
    }
}

int main(){
    int T; 
    scanf("%d", &T); getchar(); 

    for ( int tc = 0; tc < T; tc++ ){
        int N, K; // jumlah rak dan botol 
        scanf("%d %d", &N, &K); 

        int all_cost[MAX_JUMLAH]; 
        int count = 0; 

        for (int i = 0; i < K; i++){
            int B, C; 
            scanf("%d %d", &B, &C); 
            all_cost[count++] = C; 
        }

        quick_sort_recursion(all_cost, 0, count - 1); 

        // Mengambil N harga tertinggi
        long long max_profit = 0; 
        for (int i = 0; i < N && i < count; i++){
            max_profit += all_cost[i]; 
        }
        
        printf("%lld\n", max_profit); 
    
    }
}