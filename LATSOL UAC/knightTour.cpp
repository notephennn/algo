#include <stdio.h> 
#define MAX 8 

void printMap(int N, int M, int visited[MAX][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0)
                printf(". "); // Kotak belum dikunjungi
            else
                printf("%2d ", visited[i][j]); // Langkah saat kotak dikunjungi
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int x, int y, int N, int M, int visited[MAX][MAX]) {
    return (x >= 0 && x < N && y >= 0 && y < M && visited[x][y] == 0);
}

int knightTour(int move, int x, int y, int N, int M, int visited[MAX][MAX], int path[MAX * MAX][2]){
    visited[x][y] = move; 
    path[move - 1][0] = x; 
    path[move - 1][1] = y; 

    printf("Move %d:\n", move);
    printMap(N, M, visited); // Cetak peta

    if ( move == N * M) return 1; 

    if (isValidMove(x + 1, y + 2, N, M, visited) && knightTour(move + 1, x + 1, y + 2, N, M, visited, path)) return 1;
    if (isValidMove(x + 2, y + 1, N, M, visited) && knightTour(move + 1, x + 2, y + 1, N, M, visited, path)) return 1;
    if (isValidMove(x + 2, y - 1, N, M, visited) && knightTour(move + 1, x + 2, y - 1, N, M, visited, path)) return 1;
    if (isValidMove(x + 1, y - 2, N, M, visited) && knightTour(move + 1, x + 1, y - 2, N, M, visited, path)) return 1;
    if (isValidMove(x - 1, y - 2, N, M, visited) && knightTour(move + 1, x - 1, y - 2, N, M, visited, path)) return 1;
    if (isValidMove(x - 2, y - 1, N, M, visited) && knightTour(move + 1, x - 2, y - 1, N, M, visited, path)) return 1;
    if (isValidMove(x - 2, y + 1, N, M, visited) && knightTour(move + 1, x - 2, y + 1, N, M, visited, path)) return 1;
    if (isValidMove(x - 1, y + 2, N, M, visited) && knightTour(move + 1, x - 1, y + 2, N, M, visited, path)) return 1;

    visited[x][y] = 0; 
    return 0; 
}
int main(){
    int N, M; 
    char startCol; 
    int startRow; 

    scanf("%d %d %c%d", &N, &M, &startCol, &startRow);

    int startX = startRow - 1; // ngeconvert ke base 0 index 
    int startY = startCol - 'A'; 

    int visited[MAX][MAX] = {0}; 
    int path[MAX * MAX][2];  

    if ( knightTour(1, startX, startY, N, M, visited, path)){
        printf("YES\n"); 
        for (int i = 0; i < N * M; i++) {
            printf("%c%d ", path[i][1] + 'A', path[i][0] + 1);
        }
        printf("\n");
    } else {
        printf("NO\n"); 
    }
}