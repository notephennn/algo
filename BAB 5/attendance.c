#include <stdio.h>

int main(){
    int N; 
    scanf("%d", &N); 

    int pemain[105] = {0};
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int orang; 
            scanf("%d", &orang); 
            pemain[orang]++;
        }
        
    }
    int tidakTepat = 0; 
    for (int i = 1; i <= N; i++)
	{
		if (pemain[i] < N)
		{
			tidakTepat++;
		}
	}
	
	printf("%d\n", tidakTepat);
}