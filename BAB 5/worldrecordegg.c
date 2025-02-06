#include <stdio.h> 

int main(){ 
    int T; 
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int N; 
        scanf("%d", &N); 

        long long fibonacci[90]; 
        fibonacci[0] = 0; 
        fibonacci[1] = 1;
        for (int i = 2; i < N; i++)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
        
        printf("Case #%d: %lld\n", tc, fibonacci[N-1]);
    }
    
}