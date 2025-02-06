#include <stdio.h>
#include <string.h>

int main(){
    char str[1001];
    scanf("%s", str); getchar();

    int length = strlen(str);
    int palindromeCount = 0;

    // madam
    // Loop untuk panjang substring yang berbeda
    for (int sublength = 1; sublength <= length; sublength++){
        char listed[1001][1001] = {}; // palindrome ini buat ngecek aja udah dilist apa blm
        int listedPalindrome = 0; // buat ngecek keunikannya ada berapa 

        // Loop untuk setiap posisi awal substring
        for (int start = 0; start < length - sublength + 1; start++){ // supaya dia ga melebihi batas akhir dari string, makanya condition dibuat gitu 
            int left = 0; // ini dimulai dari kiri jadi gausah di - 1 karna indeks nya udah mulai dari 0
            int right = sublength - 1; // ini dimulai dari kanan yang dimana buat ngecek array trakhir dipake rumus - 1
            int isPalindrome = 1; // Flag untuk mengecek apakah palindrome

            // Mengecek apakah substring adalah palindrome
            while (left < right){
                if (str[start + left] != str[start + right]){ // kl misal dia ga sama, yaudah langsung bukan palindrome, langsung keluar dari while 
                    isPalindrome = 0;
                    break;
                }
                left++; // ini ditambah supaya nambah ke kanan
                right--; // dimulai dari kanan, jadi mundur ke kiri 
            }

            if (!isPalindrome) continue; // Lewati jika bukan palindrome

            // Mengecek apakah palindrome tersebut sudah ada di daftar
            int isUnique = 1;
            for (int i = 0; i < listedPalindrome; i++){
                if (strncmp(str + start, listed[i], sublength) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique){
                palindromeCount++;
                strncpy(listed[listedPalindrome++], str + start, sublength);
            }
        }
    }

    printf("%d\n", palindromeCount);
}
