#include <stdio.h> 
#define MAX 100 

int row, colom, price; 

void dfs(char window[MAX][MAX], int X, int Y){
    if ( X < 0 || Y < 0 || X >= row || Y >= colom || window[X][Y] == '#') return; 

    window[X][Y] = '#'; 

    dfs(window, X + 1, Y); 
    dfs(window, X - 1, Y); 
    dfs(window, X, Y + 1); 
    dfs(window, X, Y - 1); 
}

int main(){
    scanf("%d %d %d", &row, &colom, &price); getchar(); 

    char window[MAX][MAX]; 

    for ( int i = 0; i < row; i++ ){
        for ( int j = 0; j < colom; j++ ){
            scanf("%c", &window[i][j]); 
        } getchar(); 
    }

    int shards = 0; 

    for ( int i = 0; i < row; i++ ){
        for ( int j = 0; j < colom; j++ ){
            if ( window[i][j] == '-'){
                dfs(window, i, j); 
                shards++; 
            }
        }
    }

    int result = shards * price; 
    printf("%d\n", result); 
}