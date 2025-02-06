#include <stdio.h>

int main()
    {
        double N, awal = 100, bonus = 0, total = 0; 
        scanf("%lf", &N); 
        for ( int i = 0; i < N; i++)
        {
            total = awal + bonus + total; 
            bonus = bonus + 50;
        }
             printf("%0.lf\n", total);
    }