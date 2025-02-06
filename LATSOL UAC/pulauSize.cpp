#include <stdio.h> 
#define MAX 100

int grid[MAX][MAX]; // peta lautannya 
int visited[MAX][MAX]; // penanda kunjungan 
int rows, colom; 

int dfs(int X, int Y) {
    if (X < 0 || X >= rows || Y < 0 || Y >= colom || grid[X][Y] != 1 || visited[X][Y]) 
        return 0; 

    visited[X][Y] = 1; // Tandai sudah dikunjungi 

    int size = 1; // Hitung ukuran pulau
    size += dfs(X + 1, Y);  // Bawah
    size += dfs(X - 1, Y);  // Atas
    size += dfs(X, Y + 1);  // Kanan
    size += dfs(X, Y - 1);  // Kiri

    return size;
}

int main() { 
    scanf("%d %d", &rows, &colom); 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colom; j++) {
            visited[i][j] = 0;  
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colom; j++) {
            scanf("%d", &grid[i][j]); 
        }
    }

    int max_size = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colom; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) { 
                int current_size = dfs(i, j); 
                if (current_size > max_size) 
                    max_size = current_size; 
            }
        }
    }
    
    printf("%d\n", max_size); 
    return 0;
}
