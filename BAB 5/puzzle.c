#include <stdio.h> 

int main(){
    int N; 
    scanf("%d", &N); 

    int matriks[105][105]; 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matriks[i][j]);
        }
        
    }

    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (matriks[i][j] == matriks[i][k] && k != j)
                {
                    flag = 1; 
                    break; 
                } else if (matriks[i][j] == matriks[k][i] && k != j )
                {
                    flag = 1; 
                    break;
                }
            }
            
        }
        
    }
    if (flag == 0)
    {
        printf("Yay\n"); 
    } else {
        printf("Nay\n");
    }
    
}