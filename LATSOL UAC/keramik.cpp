#include <stdio.h> 
#include <string.h> 
#define MAX 100

char grid[MAX][MAX]; // Untuk menyimpan kondisi lantai
int visited[MAX][MAX]; // Untuk menandai apakah keramik sudah dicat
int N, M; // Dimensi lantai

int count_red = 0, count_green = 0, count_blue = 0;

void dfs(int X, int Y, int color){
    if ( X < 0 || Y < 0 || X >= N || Y >= M || visited[X][Y] || grid[X][Y] == '+') return; 

    visited[X][Y] = 1; 

    if ( color == 'M' ) count_red++; 
    if ( color == 'H') count_green++; 
    if ( color == 'B') count_blue++; 

    dfs(X - 1, Y, color); // Atas
    dfs(X + 1, Y, color); // Bawah
    dfs(X, Y - 1, color); // Kiri
    dfs(X, Y + 1, color); // Kanan
}

int main(){
    scanf("%d %d", &N, &M); 

    for ( int i = 0; i < N; i++ ) scanf("%s", grid[i]); 

    memset(visited, 0, sizeof(visited)); 

    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < M; j++ ){
            if ( !visited[i][j]){
                if (grid[i][j] == 'M' || grid[i][j] == 'H' || grid[i][j] == 'B') {
                    dfs(i, j, grid[i][j]);
                }
            }
        }
    }

    if (count_green >= count_blue && count_green >= count_red) {
        printf("Hijau: %d\n", count_green);
        if (count_blue >= count_red) {
            printf("Biru: %d\n", count_blue);
            printf("Merah: %d\n", count_red);
        } else {
            printf("Merah: %d\n", count_red);
            printf("Biru: %d\n", count_blue);
        }
    } else if (count_blue >= count_green && count_blue >= count_red) {
        printf("Biru: %d\n", count_blue);
        if (count_green >= count_red) {
            printf("Hijau: %d\n", count_green);
            printf("Merah: %d\n", count_red);
        } else {
            printf("Merah: %d\n", count_red);
            printf("Hijau: %d\n", count_green);
        }
    } else {
        printf("Merah: %d\n", count_red);
        if (count_green >= count_blue) {
            printf("Hijau: %d\n", count_green);
            printf("Biru: %d\n", count_blue);
        } else {
            printf("Biru: %d\n", count_blue);
            printf("Hijau: %d\n", count_green);
        }
    }
}