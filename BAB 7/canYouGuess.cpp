#include <stdio.h> 

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        long long int sum[25]; 

        for ( int j = 0; j < 25; j++ ) scanf("%lld", &sum[j]); 

        for ( int i = 0; i < 25; i++){
            int swapped = 0; 
            for ( int j = 0; j < 25 - i - 1; j++ ){
                if ( sum[j] > sum[j+1]){
                    long long int temp = sum[j]; 
                    sum[j] = sum[j+1]; 
                    sum[j+1] = temp; 

                    swapped = 1; 
                }
            }
            if (!swapped) break; 
        }

        long long int result[6]; 

        result[0] = sum[0] / 2; 
        result[1] = sum[1] - result[0]; 
        result[4] = sum[24] / 2; 
        result[3] = sum[23] - result[4]; 
        result[2] = -1; 

        for ( int i = 0; i < 25; i++ ){
            if ((sum[i] - result[0]) == (sum[24-i]- result[4])){
                result[2] = sum[i] - result[0]; 
                break; 
            }
        }

        printf("Case #%d:", tc+1); 
        for ( int i = 0; i < 5; i++){
            printf(" %lld", result[i]); 
        }

        printf("\n"); 
    }
}