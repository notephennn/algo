#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
        int Q; // bilangan bulatnya
        char S[1005]; // kodenya
        scanf("%d %[^\n]", &Q, S); 
        getchar();

        for (int i = 0; i < Q; i++)
        {
            int awal, akhir; 
            scanf("%d %d", &awal, &akhir); 

            awal--; // fungsinya karena array itukan dari 0 makanya di - 1 biar indeksnya sama
            akhir--;

            while (awal < akhir) // untuk membalikan posisi yang berada di antara indeks start dan end 
            {
                char temp = S[awal]; // menyimpan karakter pada posisi start pada variabel sementara 
                S[awal] = S[akhir]; // memasukkan string pada posisi end ke posisi start
                S[akhir] = temp; // memasukkan nilai asli dari posisi start ke posisi end 

                awal++; // ini nujukin kalau kita bergerak dari kiri ke kanan 
                akhir--; // ini nunjukin kalau akhirnya di kanan, jadi gerak dari kanan ke kiri indeksnya 
            }
            
        }
        printf("Case #%d: %s\n", tc+1, S);
    }
    
}