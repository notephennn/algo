#include <stdio.h> 

int main()
    {
        double A, B; 
        scanf("%lf %lf", &A, &B); 
        double hasil = (A-B)/A*100;
        printf("%.2lf%%\n", hasil); 
    }