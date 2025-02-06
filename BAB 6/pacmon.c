#include <stdio.h>

int N, M; 
int foodCount = 0; 
char arr[105][106]; // inputannya char semua 
int visited[105][106];

int isValid(int x, int y){
    return ( x >= 0 && x < N && y >= 0 && y < M && arr[x][y] != '#'); // ngecek inputannya gimana 
}

void countFood(int x, int y){
    if ( !isValid(x, y) || visited[x][y]){
        return; // ini fungsinya kalau udah dilewatin, jadiin pager 
    }

    visited[x][y] = 1; // tandain kalau udah dilewatin dengan flag true 

    if ( arr[x][y] == '*') foodCount++; // tambah 1 kalau ketemu makananannya 

    countFood(x+1, y); // bawah
    countFood(x-1, y); // atas
    countFood(x, y+1); // kanan 
    countFood(x, y-1); // kiri 
}
int main(){
    int T; 
    scanf("%d", &T); 
    getchar();  

    for ( int tc = 0; tc < T; tc++ ){
        scanf("%d %d", &N, &M); getchar(); 

        int pacmanX =  -1, pacmanY = -1; 
        foodCount = 0; // ini fungsinya buat ngereset setiap testcase jadi 0 
        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < M; j++ ){
                scanf("%c", &arr[i][j]); 
                if ( arr[i][j] == 'P'){
                    pacmanX = i; pacmanY = j; // ini fungsinya adalah ketika ada inputan di array nya itu P, maka yawes itu titik startnya
                }
            } getchar(); 
        }

        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < M; j++ ){
                visited[i][j] = 0; // direset ke 0 semua biar ga kecantol sama testcase sebelumnya  
            }
        }

        countFood(pacmanX, pacmanY); 

        printf("Case #%d: %d\n", tc+1, foodCount); 
    }
}