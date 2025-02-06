#include <stdio.h>

int main(){
    int N; // masukkin angka
    scanf("%d", &N); 

    int arr[105]; 
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]); // buat nyimpen valuenya
    }
    
    int Q; // ini ada berapa teman
    scanf("%d", &Q); 

    for (int i = 1; i <= Q; i++)
    {
        int X, Y; // ini untuk hari keberapa dan sampai keberapa 
        scanf("%d %d", &X, &Y); 

        int jumlah = 0;
        
        for (int j = X; j <= Y; j++)
        {
            jumlah = jumlah + arr[j]; // ini logic simple banget knp hrs dibuat susah
        }
    printf("Case #%d: %d\n", i, jumlah);    
    }
}