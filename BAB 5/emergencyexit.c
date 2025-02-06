#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 1; tc <= T; tc++)
    {
        int N, K; 
        scanf("%d %d", &N, &K); getchar();

        int firstStair = -1; 
        int lastStair = -1;
        for (int i = 0; i < N; i++)
        {
            char plot; 
            scanf("%c", &plot);
            if (plot == '1') {
                if (firstStair == -1)
                {
                    firstStair = i; 
                } else {
                    lastStair = i; 
                }
            }
            
        }
        getchar(); 
        if (K >= N || lastStair != -1 && K > firstStair && K >= N - lastStair)
        {
            printf("Case #%d: Alive\n", tc);
        } else {
            printf("Case #%d: Dead\n", tc);
        }
        
    }
    
}