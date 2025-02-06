#include <stdio.h> 

int main(){ 
    double L, B, H; 
    scanf("%lf %lf %lf", &L, &B, &H); 

    double hasil = (B*H)+(3*B*L); 
    printf("%.3lf\n", hasil); 
}