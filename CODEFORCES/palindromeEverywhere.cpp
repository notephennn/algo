#include <stdio.h> 
/*
    7
    5
    RRRRR
    5
    RRRRB
    5
    RBBRB
    6
    RBRBRB
    6
    RRBBRB
    5
    RBRBR
    12
    RRBRRBRRBRRB

    output : 
    YES
    YES
    YES
    NO
    NO
    YES
    NO
*/
int check_valid(char S[], int N){
    int has_R = 0, has_B = 0; 
    for ( int i = 0; i < N; i++ ){
        if ( S[i] == 'R') has_R = 1; 
        if ( S[i] == 'B') has_B = 1; 
    }

    if ( !has_R || !has_B ) return 1; 

    int flag = 1; 
    for ( int i = 1; i < N; i++ ){
        if ( S[i] == S[i-1]){
            flag = 0; 
            break; 
        }
    }

    return flag; 
}
int main(){
    int T; 
    scanf("%d", &T); getchar(); 

    for ( int i = 0; i < T; i++ ){
        int X; 
        char S[10000]; 
        scanf("%d", &X); getchar(); 
        scanf("%s", S); 

        if (check_valid(S, X)){
            printf("YES\n"); 
        } else printf("NO\n"); 
    }
}