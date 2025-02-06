#include <stdio.h> 
#define MAX_DATA 1000005

int arr[MAX_DATA] = {0};

int main(){
    int T, M; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
        int N; 
        scanf("%d", &N);

        int count = 0;
        for (int i = 0; i < MAX_DATA; i++)
        {
            arr[i] = 0;
        }
        
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &M);
            arr[M]++; 
        }
        for (int i = 0; i < MAX_DATA; i++)
        {
            if (arr[i] != 0)
            {
                count++;
            }
            
        }
        
        printf("Case #%d: %d\n", tc+1, count);
    }
    
}