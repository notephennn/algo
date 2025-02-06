#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++)
    {
        int N; 
        scanf("%d", &N); 

        int arr[1005]; 
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Case #%d: ", tc+1); 
        for (int i = N-1; i >= 0; i--)
        {
            printf("%d", arr[i]); 
            if (i > 0)
            {
                printf(" "); 
            }
            
        }
        printf("\n");
    }
    
}