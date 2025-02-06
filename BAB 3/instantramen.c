#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int K, N, M; 
        scanf("%d %d %d", &K, &N, &M);

        printf("Case #%d: %s\n", i+1, K <= (N+M)? "yes" : "no");
    }
    return 0;
}