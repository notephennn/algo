#include <stdio.h> 

int main(){
    int tc; 
    scanf("%d", &tc); 

    for (int T = 0; T < tc; T++)
    {
        int A;
        scanf("%d", &A); // fngsinya matriksnya nnti ada berapa kali berapa 

        long long int X[105][105], hasil[105]; // buat ngestore hasilnya nanti 
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < A; j++)
            {
                scanf("%lld", &X[i][j]); // mbuat perseginya nanti dari sini 
            }
            
        }
        printf("Case #%d: ", T+1); 
        for (int i = 0; i < A; i++)
        {
            int sum = 0; 
            for (int j = 0; j < A; j++)
            {
                sum = sum + X[j][i]; // penjumlahan per kolomnya disini 
            }
            hasil[i] = sum;
            printf("%lld", hasil[i]);
            if (i < A - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}