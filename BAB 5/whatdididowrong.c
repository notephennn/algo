#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        scanf("%d", &N); // ini buat berapa sih banyaknya barang yang dibutuhkan 

        int A[N], B[N], C[N]; // A itu untuk berapa banyaknya barang yang dibutuhkan, B itu untuk berapa banyaknya barang yang dimiliki jojo, C itu untuk store hasil dari A-B
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]); // looping buat banyak barang yang dibutuhkan
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &B[i]); // ini untuk yang jojo milikinya berapa 
        }
        printf("Case #%d: ", tc);
        for (int i = 0; i < N; i++)
        {
            C[i] = A[i] - B[i]; // fungsinya buat mengetahui dia lebih apa ga 
            printf("%d", C[i]); 
            if (i < N-1)
            {
                printf(" "); // fungsinya supaya array indeks terakhir ga ngeprint spasi
            }
            
        }
        printf("\n");
    }
    
}