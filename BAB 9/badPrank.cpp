#include <stdio.h> 
#include <string.h> 

/*
    3 
    1 
    P0DF VQP0 8 UJNF U1F5F J7 8 D8U 
    13 
    UVF 4NZR VF 83N47R 
    7 
    0L PZ MYPLUK5F M8UUF HUK J84L
*/

char convert(char c){
    switch(c){
        case '0' : return 'O'; 
        case '1' : return 'I'; 
        case '3' : return 'E'; 
        case '4' : return 'A'; 
        case '5' : return 'S'; 
        case '6' : return 'G'; 
        case '7' : return 'T'; 
        case '8' : return 'B'; 
        default : return c; 
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int T; 
    fscanf(file, "%d\n", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int K; 
        fscanf(file, "%d\n", &K); 

        char str[1005] = {}; 
        fscanf(file, "%[^\n]\n", str); 

        int len = strlen(str); 

        for ( int i = 0; i < len; i++){
            if ( str[i] >= '0' && str[i] <= '9') {
                str[i] = convert(str[i]); 
            }
        }

        for (int i = 0; i < len; i++){
            if ( str[i] != ' '){
                str[i] = str[i] - K; 
                if ( str[i] < 'A') str[i] += 26; 
            }
        }
        printf("Case #%d: %s\n", tc+1, str); 
    }

    fclose(file); 
}