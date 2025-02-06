#include <stdio.h>

int main()
    {
    double nt, nm, nu;
    scanf("%lf %lf %lf", &nt, &nm, &nu);
    double average = (nt*2/10 + nm*3/10 + nu/2);
    printf("%.2lf\n", average);
    }