#include <stdio.h> 

int main(){ 
    int T, A, B; 
    scanf("%d", &T); 
    int result[1000]; 
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A, &B); 
        if (A>B)
        {
            result[i]= 1;
        } else {
            result[i]= 0;
        }
        
    }
    for (int i = 0; i < T; i++)
    {
        if (result[i]==1)
        {
            printf("Case #%d: Go-Jo\n", i+1);
        } else {
            printf("Case #%d: Bi-Pay\n", i+1);
        }
        
    }
    
    return 0;

}