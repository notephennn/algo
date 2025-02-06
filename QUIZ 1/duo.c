#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 1; tc <= T; tc++)
    {
        int N; 
        scanf("%d", &N); 

        int arr[N]; 
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        int pairs = 0; 
        for (int j = 0; j < N; j++)
        {
            if (arr[j] == arr[j+1])
            {
                pairs++; 
                j += 2; 
            }
        }
        printf("Case #%d: %d\n", tc+1, pairs);
        
    }
    
}