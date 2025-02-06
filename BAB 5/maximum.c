#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    int coin[100005]; 
    for (int tc = 0; tc < T; tc++)
    {
        int N; 
        scanf("%d", &N); 

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &coin[i]);
        }
        int max1 = -__INT32_MAX__; 
        int max2 = -__INT32_MAX__;
        int sumMax;
        for (int j = 0; j < N; j++)
        {
            if (coin[j] >= max1)
            {
                max2 = max1; 
                max1 = coin[j];
            } 
            else if (coin[j] > max2 && coin[j] < max1)
            {
                max2 = coin[j];
            }
        }
        sumMax = max1 + max2; 
        printf("Case #%d: %d\n", tc+1, sumMax);
    }
    
}