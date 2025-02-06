#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[20];
    int poinUtama;
    int poinTambahan;
    int totalPoin;
    char grup[15];
} Peserta;

void swap(Peserta* a, Peserta* b) {
    Peserta temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Peserta daftarPeserta[], int low, int high) {
    Peserta pivot = daftarPeserta[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        int isVIPa = strcmp(daftarPeserta[j].grup, "VIP") == 0;
        int isVIPb = strcmp(pivot.grup, "VIP") == 0;

        if (isVIPa && !isVIPb) {
            i++;
            swap(&daftarPeserta[i], &daftarPeserta[j]);
        } else if ((isVIPa == isVIPb) &&
                   (daftarPeserta[j].totalPoin > pivot.totalPoin ||
                    (daftarPeserta[j].totalPoin == pivot.totalPoin &&
                     strcmp(daftarPeserta[j].nama, pivot.nama) < 0))) {
            i++;
            swap(&daftarPeserta[i], &daftarPeserta[j]);
        }
    }

    swap(&daftarPeserta[i + 1], &daftarPeserta[high]);
    return i + 1;
}

void quick_sort_recursion(Peserta daftarPeserta[], int low, int high) {
    if (low < high) {
        int pi = partition(daftarPeserta, low, high);
        quick_sort_recursion(daftarPeserta, low, pi - 1);
        quick_sort_recursion(daftarPeserta, pi + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Peserta daftarPeserta[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %s", daftarPeserta[i].nama, &daftarPeserta[i].poinUtama, 
              &daftarPeserta[i].poinTambahan, daftarPeserta[i].grup);
        daftarPeserta[i].totalPoin = daftarPeserta[i].poinUtama + daftarPeserta[i].poinTambahan;
    }

    quick_sort_recursion(daftarPeserta, 0, N - 1);

    int valid = 0; 
    for (int i = 0; i < N; i++) {
        if (daftarPeserta[i].totalPoin >= 0) {
            printf("%s\n", daftarPeserta[i].nama);
            valid = 1; 
        }
    }

    if (!valid) printf("Bangkrut Coy\n"); 

    return 0;
}
