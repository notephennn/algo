#include <stdio.h>
#include <string.h>

#define MOD 1000000007 // Mendefinisikan nilai modulo

int main() {
    FILE *file = fopen("testdata.in", "r"); // Membuka file CSV

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1; // Keluar jika file tidak ditemukan
    }

    char line[1005]; // Untuk menyimpan setiap baris
    int empty_cell = 0; // Menghitung sel kosong 

    while (fscanf(file, "%[^\n]\n", line) != EOF) {
        if (line[0] == ';') {
            empty_cell++;
        }

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ';') {
                if (i > 0 && line[i - 1] == ';') {
                    empty_cell++;
                }
            }
        }
    }

    fclose(file);
 
    long long possible = 1; 
    for (int i = 0; i < empty_cell; i++) {
        possible = (possible * 101) % MOD; // Menggunakan modulo
    }

    printf("%lld\n", possible);
    
    return 0;
}
