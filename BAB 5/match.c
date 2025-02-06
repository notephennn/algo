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
        int P, Q; 
        scanf("%d %d", &P, &Q);   
        printf("Case #%d : ", tc+1);
        if (arr[P-1] > arr[Q-1])
        {
            printf("Bibi\n");
        } else if (arr[Q-1] > arr[P-1])
        {
            printf("Lili\n");
        } else {
            printf("Draw\n");
        }
        
    }
    
}