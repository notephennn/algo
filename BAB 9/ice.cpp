#include <stdio.h> 
/*
    1
    3
    2 1 3
*/

int mutlak(int N){
    return ( N < 0 ) ? -N : N; 
}

int areas(int sumTinggi){
    return 4 * sumTinggi; // mengembalikan luas sebagai 4 * sumTinggi 
}

int perimeters(int tinggi[], int N){
    int horizontalBase = 4 * N; // menghitung jumlah keliling horizontal berdasarkan tumpukan 
    int vertikalBase = 0;  // ini untuk naiknya karena kan gatau ada berapa 

    for ( int i  = 0; i < N - 1; i++ ){
        vertikalBase = vertikalBase + mutlak(tinggi[i] - tinggi[i+1]) * 2;  // menambah hasil selisih mutlak ke vertikal base 
    }

    vertikalBase = vertikalBase + 2 * (tinggi[0] + tinggi[N-1]); // menambahkan batas kiri dan kanan tumpukan ke vertikal 
    return horizontalBase + vertikalBase; // mengembalikan total keliling dari horizontal ke vertikal 
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int T; 
    fscanf(file, "%d\n", &T); 

    for ( int tc = 0; tc < T; tc++){
        int N; 
        fscanf(file, "%d\n", &N);

        int tinggi[105] = {0}; // menyimpan tinggi tumpukan ke sebuah array 
        int sumTinggi = 0; // total tinggi tumpukan kan gatau berapa 
        for ( int i = 0; i < N; i++ ){
            fscanf(file, "%d\n", &tinggi[i]); 
            sumTinggi = sumTinggi + tinggi[i]; // menambah tumpukan tinggi ke sumTinggi 
        }

        int area = areas(sumTinggi); 
        int perimeter = perimeters(tinggi, N); 

        printf("Case #%d: %d %d\n", tc+1, perimeter, area); 
    }

    fclose(file); 
}