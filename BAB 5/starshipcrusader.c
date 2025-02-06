#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
       int N; 
       scanf("%d", &N); // fuungsinya untuk jumlah dari hasil test yang diberikan 

        int X[10005], Y[10005]; // X untuk hasil tiap test, dan Y untuk hasil minimum biar dia lulus test
        int gagal = 0; // makanya kit buat disini ada variavel gagal yang di inisialisasi dengan 0
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &X[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &Y[i]); 
            if (X[i] < Y[i])
            {
                gagal++; // ketika hasil dari test < dari hasil minimum berarti dia kan gagal makanya diplus"
            }
            
        }
        printf("Case #%d: %d\n", tc+1, gagal);
    }
    
}