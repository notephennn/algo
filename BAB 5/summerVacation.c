#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
        int N; 
        scanf("%d", &N); // masukin ada berapa inputan angkanya 

        int A[205]; 
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]); // ini untuk menyimpan angkanya 
        }

        int count = 0; // faktor kerennya berapa 
        int unique[1005] = {0}; // penanda faktor spesialnya udah muncul belum

        for (int i = 0; i < N; i++)
        {
            int flag = 1;
            for (int j = 0; j < N; j++)
            {

                for (int k = 0; k < N; k++)
                {
                    if (A[i] == A[j] + A[k] && j!=k) // jika hasil dalam penjumlahan belum pernah dihitung
                    {
                        count++;
                        flag = 0;
                        break; 
                    }
                    
                }
                if(flag == 0) break;
            }
            
            
        }
        printf("Case #%d: %d\n", tc+1, count); 
    }
    
}



// for (int i = 0; i < N; i++)
// {
//     for (int j = 0; j < N; j++)
//     {
//         int sum = 0;

//         if (i != j)
//             sum = A[i] + A[j]; // untuk nambahin masing masing angka

//         for (int k = 0; k < N; k++)
//         {
//             if (sum == A[k] && unique[sum] == 0) // jika hasil dalam penjumlahan belum pernah dihitung
//             {
//                 count++;
//                 unique[sum] = 1; // tandain aja kalau dia udah pernah muncul
//                 break; 
//             }
            
//         }
//     }
    
    
// }