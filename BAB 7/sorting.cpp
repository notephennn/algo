#include <stdio.h> 
#include <math.h> 

/*
    5
    2 -8 3 1 -10

    10
    45 9 3 -6 100 68 -57 23 -11 -25
*/

// fungsi merge sort untuk menggabungkan 2 sub array 
void merge_sort(long long int *arr, int left, int middle, int right){
    int left_length = ( middle + 1 ) - left; // fungsinya untuk menghitung panjang sub array dari kiri 
    int right_length = right - middle; // menghitung panjang sub array dari kanan 

    long long int temp_left[left_length], temp_right[right_length]; // array sementara ini buat nyimpen elemennya disini 

    for ( int i = 0; i < left_length; i++ ) temp_left[i] = arr[left + i]; 
    for ( int i = 0; i < right_length; i++) temp_right[i] = arr[middle+1+i]; 

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

int main(){
    int N; 
    scanf("%d", &N); 

    long long int A[N]; 
    for ( int i = 0; i < N; i++ ){
        scanf("%lld", &A[i]); 
    }

    merge_sort_recursion(A, 0, N-1); 

    long long int diff[N-1]; // untuk menyimpan selisih 
    int i_diff = 0; 

    for ( int i = 1; i < N; i++ ){
        diff[i_diff++] = abs(A[i] - A[i-1]); // menghitung selisih
    }

    long long int diff_max = diff[0]; 
    // menemukan selisih maksimalnya disini 
    for ( int i = 1; i < i_diff; i++ ){
        if ( diff_max < diff[i]) diff_max = diff[i]; // terus diupdate selisihnya 
    }

    int counter = 0; // berapa banyak maksimal yang ada 
    for ( int i = 1; i < i_diff; i++ ){
        if ( diff_max == diff[i]){
            counter++; // menghitung jumlah maksimum 
        }
    }

    int count = 0; // menampilkan elemen untuk pasangan maksimum 
    for ( int i = 0; i < i_diff; i++ ){
        if ( diff[i] == diff_max ){
            printf("%lld %lld\n", A[i], A[i+1]); // menampilkan pasangannya 

            if ( count < counter - 1) printf(" "); 
            else printf("\n"); 
        }
    }
}