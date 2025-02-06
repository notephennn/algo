#include <stdio.h>

// fungsi untuk memeriksa apakah ada sub array yang panjangnya tidak melebihi M 
int canFormSubarray(long long A[], int N, int length, long long M) {
    long long sum = 0;  // inisialisasi sub array pertama 

    // Hitung jumlah dari subarray pertama dengan panjang tertentu
    for (int i = 0; i < length; i++) {
        sum += A[i];
    }
    
    if (sum <= M) return 1; // kalau bener ada, tandain jadi 1 

    for (int i = length; i < N; i++) {
        sum = sum - A[i - length] + A[i]; // kurangi elemen kiri, tambahkan dikanan 
        if (sum <= M) return 1; // kalau masih memenuhi, kembalikan 1 
    }

    return 0;
}

int max_addition(long long A[], int N, long long M) {
    int left = 0, right = N;
    int maxLength = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFormSubarray(A, N, mid, M)) {
            maxLength = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxLength;
}

int main(){
    int N; 
    scanf("%d", &N); 

    long long A[N]; 
    for ( int i = 0; i < N; i++ ){
        scanf("%lld", &A[i]); 
    }

    int Q; 
    scanf("%d", &Q); 

    long long maxAddition[Q+1]; 

    for ( int i = 0; i < Q; i++ ){
        long long M; 
        scanf("%lld", &M); 

        long long result = max_addition(A, N, M); 

        printf("Case #%d: %lld\n", i+1, result); 
    }
}