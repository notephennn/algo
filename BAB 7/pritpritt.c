#include <stdio.h> 

/*
    5
    154 172 158 164 160 
    4
    154 
    172
    155
    164
*/

// fungsi merge sort untuk menggabungkan 2 sub array 
void merge_sort(long long int *arr, int left, int middle, int right){
    int left_length = ( middle + 1 ) - left; // fungsinya untuk menghitung panjang sub array dari kiri 
    int right_length = right - middle; // menghitung panjang sub array dari kanan 

    long long int temp_left[left_length], temp_right[right_length]; // array sementara ini buat nyimpen elemennya disini 

    for ( int i = 0; i < left_length; i++ ) temp_left[i] = arr[left + i]; 
    for ( int i = 0; i < right_length; i++) temp_right[i] = arr[(middle + 1)+i]; 

    int i, j, k; // indeks untuk sub array ke dalam array utama 

    // menggabungkan sub array sementara ke dalam array utama 
    for ( int i = 0, j = 0, k = left; k <= right; k++){
        if ( i < left_length && ( j >= right_length || temp_left[i] <= temp_right[j] )){
            arr[k] = temp_left[i++]; // menyalin sub array dari kiri
        } else {
            arr[k] = temp_right[j++]; // menyalin sub arry dari kanan 
        }
    }
}

// fungsi buat ngelakuin rekursi mergesort 
void merge_sort_recursion(long long int *arr, int left, int right){
    if ( left >= right ) return; // jika tidak ditemukan 

    int middle = left + ( right - left ) / 2; // untuk mencari indeks yang ditengah 

    merge_sort_recursion(arr, left, middle); // rekursi kiri 
    merge_sort_recursion(arr, middle+1, right); // rekursi kanan 

    merge_sort(arr, left, middle, right); // digabungin lagi 
}

// fungsi untuk mencari value yang dicari 
int search(long long int *arr, int left, int right, long long int value){
    if ( left > right ) return -1; 

    int middle =  left + ( right - left ) / 2; 

    if ( arr[middle] == value ) return middle; // jika ditemukan 
    else if ( arr[middle] > value ) return search(arr, left, middle-1, value); // kiri
    else return search(arr, middle+1, right, value); // kanan 
}   

int main(){
    int N; 
    scanf("%d", &N); 

    long long int A[N], X;  
    for ( int i = 0; i < N; i++ ){
        scanf("%lld", &A[i]); 
    }

    merge_sort_recursion(A, 0, N-1); 

    int Q; 
    scanf("%d", &Q); 

    for ( int i = 0; i < Q; i++ ){
        scanf("%lld", &X); 

        int X_index = search(A, 0, N - 1, X); 

        printf("%d\n", X_index+ ( X_index == -1 ? 0 : 1)); 
    }
}