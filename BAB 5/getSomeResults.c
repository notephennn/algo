#include <stdio.h>

int main()
{
    long long int matrix1[50][50], matrix2[50][50], matrix3[50][50];
    long long int matrix12[50][50], matrix123[50][50];
    
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++)
    {
        int size;
        scanf("%d", &size);

        // Input matrix1
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                scanf("%lld", &matrix1[row][column]);
            }
        }

        // Input matrix2
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                scanf("%lld", &matrix2[row][column]);
            }
        }

        // Input matrix3
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                scanf("%lld", &matrix3[row][column]);
            }
        }

        // Mengalikan matrix1 dengan matrix2 untuk mendapatkan matrix12
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                matrix12[row][column] = 0;  // Inisialisasi
                for (int k = 0; k < size; k++)
                {
                    matrix12[row][column] += matrix1[row][k] * matrix2[k][column];
                }
            }
        }

        // Mengalikan matrix12 dengan matrix3 untuk mendapatkan matrix123
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                matrix123[row][column] = 0;  // Inisialisasi
                for (int k = 0; k < size; k++)
                {
                    matrix123[row][column] += matrix12[row][k] * matrix3[k][column];
                }
            }
        }

        // Output hasil matrix123
        printf("Case #%d:\n", i);
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                if (column == size - 1)
                {
                    printf("%lld", matrix123[row][column]);
                }
                else
                {
                    printf("%lld ", matrix123[row][column]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
