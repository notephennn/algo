#include <stdio.h> 
#include <math.h> 
/*
    5
    1 2
    1 5
    2 2
    10 20
    1 100000000

    2
    3
    1
    5
    44721
*/
// long long findMaxLength(long long left, long long right){
//     long long maxLength = 0; // nyimpen maksimal subaraay nya 

//     for ( int i = left; i <= right; i++ ){
//         int length = 1; // panjang array yang baik itu dimulai dr 1 
//         int prev = i; 
//         int diff = 1; // selisih pertama minimal 1 

//         while ( prev + diff <= right ){
//             prev = prev + diff; 
//             diff++;
//             length++; 
//         }

//         if ( length > maxLength ) maxLength = length; 
//     }   

//     return maxLength; 
// }

long long findMaxLength(long long l, long long r) {
    return (long long)(sqrt(2 * (r - l) + 0.25) + 0.5);
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        long long N, M; 
        scanf("%lld %lld", &N, &M); 

        long long result = findMaxLength(N, M); 
        printf("%lld\n", result); 
    }
}