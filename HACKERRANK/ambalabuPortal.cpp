#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[] = {-1, 1, 0, 0};  
int dy[] = {0, 0, -1, 1};
int portal_num = 0;
int N, M;  
char peta[50][50]; 
int visited[50][50];  
int portal[10][2];      

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0 && peta[nx][ny] != '#') {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }

    if (peta[x][y] >= '1' && peta[x][y] <= '9') {
        int portal_num = peta[x][y] - '0'; 
        int px = portal[portal_num][0];
        int py = portal[portal_num][1];

        if (visited[px][py] == 0) {
            visited[px][py] = 1;
            dfs(px, py);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int tc= 0; tc < t; tc++) {
        scanf("%d %d", &N, &M);  

        int startX = -1, startY = -1;

        for (int i = 0; i < N; i++) {
            scanf("%s", peta[i]);
            for (int j = 0; j < M; j++) {
                if (peta[i][j] == 'X') {
                    startX = i;
                    startY = j;
                }
                if (peta[i][j] >= '1' && peta[i][j] <= '9') {
                    portal[portal_num][0] = peta[i][j] - '0';
                    portal[portal_num][1] = i;
                    portal[portal_num][2] = j;  
                    portal_num++;
                }
            }
        }
        memset(visited, 0, sizeof(visited));

        dfs(startX, startY);

        int explored = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 1) {
                    explored++;
                }
            }
        }

        printf("Case #%d: %d\n",tc+1, explored);  
    }

    return 0;
}
