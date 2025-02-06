#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char a[], char b[]) {
    char temp[55];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


int partition(char nama[][55], int X[], int low, int high) {
    int pivotX = X[high];       
    char pivotNama[55];
    strcpy(pivotNama, nama[high]); 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (X[j] > pivotX || (X[j] == pivotX && strcmp(nama[j], pivotNama) < 0)) {
            i++;
            swap(&X[i], &X[j]);
            swapString(nama[i], nama[j]);
        }
    }

    swap(&X[i + 1], &X[high]);
    swapString(nama[i + 1], nama[high]);

    return i + 1;
}

void quickSort(char nama[][55], int X[], int low, int high) {
    if (low < high) {
        int pi = partition(nama, X, low, high);

        quickSort(nama, X, low, pi - 1);
        quickSort(nama, X, pi + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char nama[N][55];
    int X[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", nama[i], &X[i]);
    }

    quickSort(nama, X, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", nama[i], X[i]);
    }

    return 0;
}
