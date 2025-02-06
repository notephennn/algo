#include <stdio.h> 

int main(){ 
    double A, B, C, D; 
    scanf("(%lf+%lf)x(%lf-%lf)", &A, &B, &C, &D); getchar();
    double hasil1 = (A+B)*(C-D);
    scanf("(%lf+%lf)x(%lf-%lf)", &A, &B, &C, &D); getchar();
    double hasil2 = (A+B)*(C-D);
    scanf("(%lf+%lf)x(%lf-%lf)", &A, &B, &C, &D);
    double hasil3 = (A+B)*(C-D);
    printf("%.0lf %.0lf %.0lf\n", hasil1, hasil2, hasil3);
}