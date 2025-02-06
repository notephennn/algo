#include <stdio.h> 

int main(){
    int N; 
    scanf("%d", &N); // fungsinya buat masukin ada berapa banyak barang 
    int X[N]; 

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &X[i]);// fungsinya buat ngeinput banyaknya barang sejumlah N 
    }
    int Q; 
    scanf("%d", &Q); // fungsinya buat kita tahu berapa kali katalog itu di update 
    for (int i = 1; i <= Q; i++)
    {
        int awal, akhir; 
        scanf("%d %d", &awal, &akhir); // fungsi dari awal ini harga awalnya berapa, fungsi dari akhir ini setelah diupdate jadi berapa 

        X[awal - 1] = akhir; // fungsinya buat mengubah nilai update pada inputan user 

        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++)
        {
            printf("%d", X[j]);

            if (j < N - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    
}