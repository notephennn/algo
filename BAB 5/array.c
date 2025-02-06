#include <stdio.h> 

int main(){
    int N; 
    scanf("%d", &N); 
    int index[1005], nomor[1005], hasil[1005]; 
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &index[i]); // index arraynya keberapa
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nomor[i]); // ini buat masukin nomornya ke index 
        hasil[index[i]] = nomor[i];
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", hasil[i]); 
        if ( i < N - 1)
        {
            printf(" ");
        }
        
    }
    printf("\n");
}