#include <stdio.h> 
#include <stdbool.h> 
#define MAX_NUMBER_ARR 10000
int A[MAX_NUMBER_ARR] = {0}; 

int main(){
    int N; 
    int happyCustomer = 0;  

    scanf("%d", &N);

    for (int tc = 0; tc < N; tc++)
    {
        scanf("%lld", &A[tc]); // ini nomor kamarnya 
        bool happy = true; // anggep aja semuanya happy dulu
        for (int i = 0; i < tc; i++) // untuk ngecek angka yang baru dimasukkan di A[i] udah pernah muncul di array A sebelumnya apa ngga 
        {
            if (A[tc] == A[i])
            {
                happy = false; // kl dia udah pernah muncul berarti langsung aja ga dimasukin
                break;
            }
            
        }
        if (happy)
        {
            happyCustomer++; // kl dia blm pernah muncul di sebelumnya yaudah di ++ aja
        }
        
    }
    printf("%d\n", happyCustomer);
}