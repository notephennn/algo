#include <stdio.h>

int isSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *file = fopen("testdata.in", "r");     
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    int X;
    int pageNumber = 1; // Menandakan nomor halaman
    int wordCount = 0;  // Menghitung jumlah kata di halaman
    int pageFound = 0;  // Penanda apakah ada halaman dengan jumlah kata kurang dari X

    fscanf(file, "%d\n", &X);

    char c;
    int inWord = 0;  // Menandakan apakah kita sedang berada di dalam sebuah kata

    while ((c = fgetc(file)) != EOF) {
        if (c == '#') {
            if (wordCount < X) {
                printf("page %d: %d word(s)\n", pageNumber, wordCount);
                pageFound = 1;  // Menandai ada halaman yang jumlah katanya kurang dari X
            }
            wordCount = 0;
            pageNumber++;
        } else if (isSpace(c)) {
            inWord = 0;  // Tandakan kita tidak sedang berada di dalam kata
        } else {
            if (!inWord) {
                wordCount++;  // Hitung kata baru
                inWord = 1;   // Tandakan kita sedang berada di dalam kata
            }
        }
    }

    if (!pageFound) {
        printf("The essay is correct\n");
    }

    fclose(file); 
    return 0;
}
