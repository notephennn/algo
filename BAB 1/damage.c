#include <stdio.h>

int main()
    {
    double ph, m, pu;
    scanf("%lf %lf %lf", &ph, &m, &pu);
    double average = (ph*2/10 + m*3/10 + pu/2);
    printf("%.2lf\n", average);
    }