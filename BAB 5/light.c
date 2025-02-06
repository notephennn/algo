#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
        int N, M, Q; // untuk memasukkan jumlah temen jojo, jumlah lorongnya berapa, temen yang berkunjung 
        scanf("%d %d %d", &N, &M, &Q);

        int arr[55][55]; // pola untuk menyimpan temannya
        int ruangan[55] = {0}; 

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &arr[i][j]); // buat simpen data cetekannya
            }
        }

        for (int i = 0; i < Q; i++) // memproses temen yang berkunjung
        {
           int X; 
           scanf("%d", &X); // terteuju untuk temannya yang mau dipake yang mana 
           for (int j = 0; j < M; j++) // bandingin satu" 
           {
                ruangan[j] += arr[X-1][j]; // ini untuk nunjukin temen yang ke X, berkunjung pada lorong J. 
           }   
        }

        printf("Case #%d:\n", tc+1); 

        for (int i = 0; i < M; i++)
        {
            if (ruangan[i] % 2 == 1) // jika dicetek ganjil maka yes
            {
                printf("YES\n");
            } else {
                printf("NO\n"); // kl dicetek genap maka no
            }
            
        }
        
    }
    
}