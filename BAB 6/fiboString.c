#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000 // Untuk batasan maksimum Fibonacci string

void fibo(int N, char hasil[], char fx[], char fy[]) {
    if (N == 0) {
        strcpy(hasil, fx); 
        return;
    }
    if (N == 1) {
        strcpy(hasil, fy); 
        return;
    }

    char f1[MAX_SIZE]; // F(n-1)
    char f2[MAX_SIZE]; // F(n-2)

    // Memanggil rekursif untuk F(n-1) dan F(n-2)
    fibo(N - 1, f1, fx, fy); // Menghitung F(n-1)
    fibo(N - 2, f2, fx, fy); // Menghitung F(n-2)

    // Menggabungkan hasil
    strcpy(hasil, f1);   // Menyalin F(n-1) ke hasil
    strcat(hasil, f2);   // Menambahkan F(n-2) ke hasil
}

int main() {
    int T;
    scanf("%d", &T); 

    char hasil[MAX_SIZE]; // Array untuk menyimpan hasil

    for (int tc = 0; tc < T; tc++) {
        int X;
        char Y[2], Z[2]; 
        scanf("%d %s %s", &X, Y, Z); // Input nilai X, F(0), dan F(1)

        fibo(X, hasil, Y, Z);
        printf("Case #%d: %s\n", tc + 1, hasil);
    }
}
