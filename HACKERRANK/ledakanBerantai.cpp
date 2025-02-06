#include <stdio.h>
#define MAX 55

int rows, colom, granat_radius; 
char map[MAX][MAX]; 
int dx[] = {-1, 1, 0, 0}; // Arah gerakan: atas, bawah, kiri, kanan
int dy[] = {0, 0, -1, 1}; 

void spread_granat(int x, int y, int radius){
    // Menyebarkan ledakan granat
    for (int gerakan = 0; gerakan < 4; gerakan++) {
        for (int i = 1; i <= radius; i++) { 
            int nx = x + dx[gerakan] * i; // posisi baru dari x
            int ny = y + dy[gerakan] * i; // posisi baru dari y

            if (nx >= 0 && nx < rows && ny >= 0 && ny < colom) {
                // Jika musuh, ubah menjadi kosong
                if (map[nx][ny] == 'O') {
                    map[nx][ny] = '.'; 
                }

                if (map[nx][ny] >= '1' && map[nx][ny] <= '9') {
                    int dinamit_radius = map[nx][ny] - '0'; // Dapatkan radius ledakan dinamit
                    map[nx][ny] = '.';  // Ubah dinamit menjadi kosong setelah ledakan
                    spread_granat(nx, ny, dinamit_radius);  
                }
            } else {
                break; 
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d %d", &rows, &colom, &granat_radius); 
        getchar(); 

        for (int i = 0; i < rows; i++) {
            scanf("%s", map[i]);
        }

        int granat_x = -1, granat_y = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colom; j++) {
                if (map[i][j] == 'X') {
                    granat_x = i;
                    granat_y = j;
                    break;
                }
            }
            if (granat_x != -1) break; 
        }

        spread_granat(granat_x, granat_y, granat_radius); 

        int remaining_enemies = 0; 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colom; j++) {
                if (map[i][j] == 'O') { // Jika ada musuh yang belum terkena ledakan
                    remaining_enemies++; 
                }
            }
        }

        printf("Case #%d: %d\n", tc + 1, remaining_enemies); 
    }

    return 0;
}
