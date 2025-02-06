    #include <stdio.h> 
    #include <string.h>

    /*
        Di soal diminta menggunakan function untuk membalikkan sebuah string 
    */

    void membalikString(char str[]){
        int length = strlen(str);       // dapetin panjang string
        char temp;                      // Variabel sementara untuk pertukaran
        int start = 0;                  // Indeks awal array
        int end = length - 1;           // Indeks akhir array

        while (start < end) {
            // Tukar karakter di posisi awal dengan yang di akhir
            temp = str[start];          
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }

    }

    int main(){
        int T; 
        scanf("%d", &T); getchar();

        for ( int tc = 0; tc < T; tc++){
            char str[1005]; 
            scanf("%[^\n]", str); getchar();

            membalikString(str); 

            printf("Case #%d: %s\n", tc+1, str);  
        }
    }