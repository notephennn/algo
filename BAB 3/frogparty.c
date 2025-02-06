#include <stdio.h> 

int main(){ 
    long long T; 
    scanf("%lld", &T); 
    int result[1000]; 

    for (int i = 0; i < T; i++)
    {
        long long N, M; 
        scanf("%lld %lld", &N, &M);
        if ((M*N)%2==0)
        {
            result[i]=0;
        } else{
            result[i]=1;
        }        
        
    }

    for (int i = 0; i < T; i++){
        if ( result[i]==1 ) {
        printf("Case #%d: Need more frogs\n", i+1);
    } else {
        printf("Case #%d: Party time!\n", i+1);
        }
    }
    
    return 0;
    
}