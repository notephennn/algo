#include <stdio.h> 

int main(){ 
    int T, A, B, C; 
    int result[1000];

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &A, &B, &C);

        int cashback = (A * B / 100);

        if (cashback > C)
        {
            result[i] = C;
        } else {
            result[i] = cashback;
        }
        
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %d\n", i+1, result[i]);
    }
    
    

}