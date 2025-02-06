#include <stdio.h> 

/*
    Soalnya minta apakah dia bisa mengerucutkan ke 1, kl bisa yes, kl ga ya no 
*/

int kemungkinan(int N, int M){
    if ( N == M ) return 1; // kalau udah sama yawes balikin ke true 
    else if ( N == 1 ) return 0; // ini karena gamungkin N > M, jadinya gaakan mencapai M
    else if ( N % 2 == 0 ) return kemungkinan(N/2, M); 
    else if ( N % 2 != 0 ) return kemungkinan(N*3+1, M); 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N, M; 
        scanf("%d %d", &N, &M); 

        printf("Case #%d: ", tc+1); 
        if ( kemungkinan(N, M)){
            printf("YES\n"); 
        } else {
            printf("NO\n");
        }
    }
}