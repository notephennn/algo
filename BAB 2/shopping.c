#include <stdio.h> 

int main(){ 
    double N, P; 

    double temp1, temp2, temp3, temp4;
    scanf("%lf %lf", &N, &P); 
    temp1 = (P*100)/(100-N);
    scanf("%lf %lf", &N, &P); 
    temp2 = (P*100)/(100-N); 
    scanf("%lf %lf", &N, &P); 
    temp3 = (P*100)/(100-N); 
    scanf("%lf %lf", &N, &P); 
    temp4 = (P*100)/(100-N); 
    printf("$%.2lf\n", temp1);
    printf("$%.2lf\n", temp2);
    printf("$%.2lf\n", temp3);
    printf("$%.2lf\n", temp4);
}