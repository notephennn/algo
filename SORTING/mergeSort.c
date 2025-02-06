#include <stdio.h> 

/*
    O n ( log n )
*/

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;        // panjang bagian kiri 
    int n2 = right - mid;          // panjang bagian kanan 

    int leftArr[n1], rightArr[n2];

    // menyimpan salinan array ke data sementara 
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // proses penggabungan 
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // nyalin sisa elemen 
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;       // mengambil bagian tengah 

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(){
    int N; 
    scanf("%d", &N); 

    int A[N]; 
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); 
    }

    merge_sort(A, 0, N-1); 

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]); 
    }
    printf("\n");

    return 0;
}
