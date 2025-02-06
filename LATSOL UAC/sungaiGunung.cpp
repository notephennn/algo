#include <stdio.h> 

int row, colom; 
int map[100][100];
int visited[100][100]; 

void dfs(int X, int Y, int prev_height){
    if ( X < 0 || X >= colom || Y < 0 || Y >= row || visited[Y][X] || map[Y][X] > prev_height) return; 

    visited[Y][X] = 1; 

    dfs(X - 1, Y, map[Y][X]); // Atas
    dfs(X + 1, Y, map[Y][X]); // Bawah
    dfs(X, Y - 1, map[Y][X]); // Kiri
    dfs(X, Y + 1, map[Y][X]); // Kanan
}

int main(){
    scanf("%d %d", &row, &colom); 

    for ( int i = 0; i < row; i++ ){
        for ( int j = 0; j < colom; j++ ){
            scanf("%d", &map[i][j]); 
        }
    } 

    int X, Y; 
    scanf("%d %d", &X, &Y); 

    dfs(X, Y, map[Y][X]); 

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colom; j++) {
            if ( j > 0 ) printf(" "); 
            if (visited[i][j]) 
                printf("W");
            else 
                printf(".");
        }
        printf("\n");
    }
}