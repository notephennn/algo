#include <stdio.h> 

int main(){
    int N; 
    scanf("%d", &N); 
    
    long long int max = 0; 
    int arr[100005]; 
    int minOdd = 999999; 
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]); 
        max = max + arr[i];

        if (arr[i] % 2 == 1)
        {
            minOdd = (minOdd < arr[i]) ? minOdd : arr[i];
        }
        
    }

    if (max % 2 == 0)
    {
        printf("%lld\n", max);
    } else {
        printf("%lld\n", max - minOdd);
    }
}