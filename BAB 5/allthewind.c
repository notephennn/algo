#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 1; tc <= T; tc++)
    {
        int A;
        scanf("%d", &A); // fngsinya matriksnya nnti ada berapa kali berapa 

        long long int X[105][105]; // buat ngestore hasilnya nanti 
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < A; j++)
            {
                scanf("%lld", &X[i][j]); // mbuat perseginya nanti dari sini 
            }
            
        }
        long long hasil[100] = {0};
		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < A; j++)
			{
				hasil[i] = hasil[i] + X[j][i];
			}
		}
		
		printf("Case #%d: ", tc);
		for (int i = 0; i < A; i++)
		{
			printf("%lld", hasil[i]);
			
			if (i < A-1)
			{
				printf(" ");
			}
		}
		printf("\n");
    }
    
}