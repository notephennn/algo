#include <stdio.h> 
#include <stdlib.h> 
#define MAX 105

char map[MAX][MAX]; 
int visited[MAX][MAX]; 
int N, M; 
int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 

int dfs(int X, int Y, char type){
    visited[X][Y] = 1; 

    int size = 1; 

    for (int i = 0; i < 4; i++) {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == type) {
            size += dfs(nx, ny, type);  // Rekursi untuk menemukan pasukan yang lebih besar
        }
    }
    
    return size;
}

int main(){
    int T; 
    scanf("%d", &T); 
    getchar(); 

    for ( int tc = 0; tc < T; tc++ ){
        scanf("%d %d", &M, &N); 
        getchar(); 

        for ( int i = 0; i < M; i++ ){
            for ( int j = 0; j < N; j++ ) {
                scanf("%c", &map[i][j]);
            } 
            getchar(); 
        }

        for ( int i = 0; i < M; i++ ){
            for ( int j = 0; j < N; j++) visited[i][j] = 0; 
        }

        int caesar_max = 0, napoleon_max = 0, caesar_min = 99999, napoleon_min = 99999; 

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 'C' && !visited[i][j]) {
                    int size = dfs(i, j, 'C');
                    caesar_max = (size > caesar_max) ? size : caesar_max;
                    caesar_min = (size < caesar_min) ? size : caesar_min;
                }
                if (map[i][j] == 'N' && !visited[i][j]) {
                    int size = dfs(i, j, 'N');
                    napoleon_max = (size > napoleon_max) ? size : napoleon_max;
                    napoleon_min = (size < napoleon_min) ? size : napoleon_min;
                }
            }
        }

        if (caesar_min == 99999) caesar_min = 0;
        if (napoleon_min == 99999) napoleon_min = 0;

        int caesarScore = caesar_max - napoleon_min;
        int napoleonScore = napoleon_max - caesar_min;
        
        printf("Case #%d: ", tc+1);
        
        if (caesarScore > napoleonScore) {
            printf("Caesar\n");
        } else if (caesarScore < napoleonScore) {
            printf("Napoleon\n");
        } else {
            printf("Draw\n");
        }
    }

    return 0;
}
