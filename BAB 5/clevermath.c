#include <stdio.h>

int main(){ 
    int T; 
    scanf("%d", &T); 

    for (int i = 0; i < T; i++)
    {
        int A, B; 
        scanf("%d %d", &A, &B);
        int hasil = 0; // ngereset ke 0
        int count = 1; // buat ratusan puluhan satuan
        do
        {
            hasil += ((A % 10) + (B % 10)) % 10 * count;
            A = A / 10; 
            B = B / 10;
            count = count * 10; // untuk puluhan dan ratusan 
        } while (A != 0 || B != 0); // kl pas dibagi dia = 0
    printf("Case #%d: %d\n", i+1, hasil);
    } 
}