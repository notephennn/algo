#include <stdio.h> 

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    int L[n1], R[n2]; 
    for ( int i = 0; i < n1; i++ ) L[i] = arr[left + i]; 
    for ( int j = 0; j < n2; j++ ) R[j] = arr[mid + 1 + j]; 

    int i = 0, j = 0, k = left; 
    while ( i < n1 && j < n2){
        if ( L[i] <= R[j]) arr[k++] = L[i++]; 
        else arr[k++] = R[j++]; 
    }

    while ( i < n1 ) arr[k++] = L[i++]; 
    while ( j < n2 ) arr[k++] = R[j++]; 
}

void merge_sort(int arr[], int left, int right){
    if ( left < right){
        int mid = left + ( right - left ) / 2; 

        merge_sort(arr, left, mid); 
        merge_sort(arr, mid+1, right); 

        merge(arr, left, mid, right); 
    }
}

int linear_search(int arr[], int N){
    for ( int i = 0; i < N; i++ ){
        if ( arr[i] == arr[i-1]) return 1; 
    }

    return -1; 
}

int main(){
    int N; 
    scanf("%d", &N); 

    int A[N]; 
    for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]); 

    merge_sort(A, 0, N-1); 

    // for ( int i = 0; i < N; i++ ) printf("%d ", A[i]); 

    if ( linear_search(A, N)) printf("Terdapat duplikat\n"); 
    else printf("tidak terdapat duplikat\n");   
}