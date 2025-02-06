#include <stdio.h> 

/*
    2
    5 5
    #####
    #S..#
    ###.#
    #...#
    #####
    2 2
    S.
    .#

*/
int A, B; 
char arr[105][106]; 
int titikCount = 0; 
int visited[105][106]; 

int isValid( int x, int y){
    return ( x >= 0 && x < A && y >= 0 && y < B && arr[x][y] != '#' );
}

void count(int x, int y){
    if ( !isValid(x,y) || visited[x][y]) {
        return;
    } 

    visited[x][y] = 1; // tandain kll titik nya udah dilewatin 

    if ( arr[x][y] == '.') titikCount++; 

    count(x+1, y); 
    count(x-1, y); 
    count(x, y+1); 
    count(x, y-1); 
}

int main(){
    int T;  
    scanf("%d", &T); getchar(); 

    for ( int tc = 0; tc < T; tc++ ){
        scanf("%d %d", &A, &B); getchar(); // getchar ini fungsinya apa? drtd salah terus dikasih getchar bener 

        int X = -1, Y = -1;
        titikCount = 0;  
        for ( int i = 0; i < A; i++ ){
            for ( int j = 0; j < B; j++ ){
                scanf("%c", &arr[i][j]); 
                if ( arr[i][j] == 'S'){
                    X = i, Y = j; 
                }
            } getchar(); 
        }
        
        for ( int i = 0; i < A; i++){
            for ( int j = 0; j < B; j++ ){
                visited[i][j] = 0; 
            }
        }

        count(X, Y); 
        printf("Case #%d: %d\n", tc+1, titikCount); 
    }
}