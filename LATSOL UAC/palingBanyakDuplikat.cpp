#include <stdio.h> 

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    int L[n1], R[n2]; 
    for ( int i = 0; i < n1; i++ ) L[i] = arr[left + i]; 
    for ( int j = 0; j < n2; j++ ) R[j] = arr[mid + 1 + j]; 

    int i = 0, j = 0, k = left; 
    while ( i < n1 && j < n2 ) {
        if ( L[i] <= R[j]) arr[k++] = L[i++]; 
        else arr[k++] = R[j++]; 
    }

    while ( i < n1) arr[k++] = L[i++]; 
    while ( j < n2 ) arr[k++] = R[j++]; 
}

void merge_sort(int arr[], int left, int right){
    if ( left < right ){
        int mid = left + ( right - left ) / 2; 

        merge_sort(arr, left, mid); 
        merge_sort(arr, mid+1, right); 

        merge(arr, left, mid, right); 
    }
}

int max(int arr[], int N){
    int max_freq = 1; 
    int current_freq = 1; 
    int most = arr[0]; 

    for ( int i = 0; i < N; i++ ){
        if ( arr[i] == arr[i-1]){
            current_freq++; 
        } else {
            if ( current_freq > max_freq){  
                max_freq = current_freq; 
                most = arr[i-1]; 
            }
            current_freq = 1; 
        }
    }

    if ( current_freq > max_freq ) {
        max_freq = current_freq;
        most = arr[N-1]; 
    } 

    return most; 
}

int main(){
    int N; 
    scanf("%d", &N); 

    int A[N]; 
    for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]); 

    int result = max(A, N); 
    printf("%d\n", result); 
}