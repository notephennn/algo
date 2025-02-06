#include <stdio.h> 
#include <string.h> 

int main(){
    int T;
    scanf("%d", &T); 
    getchar();

    for (int tc = 0; tc < T; tc++)
    {
        char nama[100005]; 
        scanf("%[^\n]", &nama); 
        getchar();

        int alphabet[26] = {0}; // fungsinya buat melacak huruf yang akan muncul 
        int unique = 0; // menghitung jumlah huruf berbedanya ada berapa 
        for (int i = 0; i < strlen(nama); i++)
        {
            int index = nama[i] - 'a'; // fungsinya buat mengubah karakter ke index arry jadi a = 0; b = 1; 
            if (alphabet[index] == 0)
            {
                unique++; // jika huruf yang ada belum pernah muncul, tambahkan ke jumlah huruf berbeda 
                alphabet[index] = 1; // kalau sudah ditambahkan jangan lupa ditandain kl sudah pernah muncul 
            }
            
        }
        printf("Case #%d: ", tc+1);
        if (unique % 2 == 0)
        {
            printf("Yay\n");
        } else {
            printf("Ewwww\n");
        }
          
    }
    
}