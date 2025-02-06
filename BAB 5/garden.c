#include <stdio.h> 

int main(){
    int X, Y; 
    scanf("%d %d", &X, &Y); 

    int garden[105][105]; 
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            scanf("%d", &garden[i][j]); // membuat matriksnya X x Y
        }
        
    }
    int change; 
    scanf("%d", &change); // ini buat menerima perubahan dari indeksnya 
    for (int i = 0; i < change; i++)
    {
        int A, B, C; 
        scanf("%d %d %d", &A, &B, &C); // buat angkanya, A untuk X, B untuk Y, C untuk angka diupdate 

        garden[A-1][B-1] = C; // buat ngubah jadi matriks baru 
    }
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            printf("%d", garden[i][j]); // buat matriks 

            if (j < Y - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}