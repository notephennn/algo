#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 1; tc <= T; tc++)
    {
        int N; 
        scanf("%d", &N);  

        int tabel[505][505]; 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &tabel[i][j]);
            }
            
        }
        printf("Case #%d: ", tc);
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum = sum + tabel[j][i];
            }
            printf("%d", sum);
            if (i < N-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}