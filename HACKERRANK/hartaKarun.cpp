#include <stdio.h> 
#define MAX 105

char grid[MAX][MAX]; // peta lauutannya 
int visited[MAX][MAX]; // penanda kunjungannya 
int rows, colom; 
int dx[] = {1, -1, 0, 0}; // arah gerakan ( kanan kiri atas bawah )
int dy[] = {0, 0, 1, -1}; 

int dfs(int X, int Y){
    // jika sudah dikunjungi atau bukan bagian dari pulau
    if ( X < 0 || X >= rows || Y < 0 || Y >= colom || grid[X][Y] != '1' || visited[X][Y]) return 0; 

    visited[X][Y] = 1; // tandain sudah pernah dikunjungin 
    int size = 1; // ukuran pulaunya kan awalnya 1 

    for ( int i = 0; i < 4; i++ ){
        int nx = X + dx[i]; // menghitung posisi baru x 
        int ny = Y + dy[i]; // menghitung posisi baru y 

        size = size + dfs(nx, ny); // tambahkan pulau yang terhubung 
    }

    return size; 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ) {
        scanf("%d %d", &rows, &colom); 

        for ( int i = 0; i < rows; i++ ) scanf("%s", &grid[i]); 

        for ( int i = 0; i < rows; i++ ){
            for ( int j = 0; j < colom; j++ ){
                visited[i][j] = 0; 
            }
        }

        int max_size = 0; 

        for ( int i = 0; i < rows; i++ ){
            for ( int j = 0; j < colom; j++ ){
                if ( grid[i][j] == '1' && !visited[i][j]){
                    int current_size = dfs(i, j); 
                    if ( current_size > max_size ) max_size = current_size; 
                }
            }
        }

        printf("Case #%d: %d\n", tc+1, max_size); 
    }
}