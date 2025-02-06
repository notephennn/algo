#include <stdio.h> 

/*
    fungsi dari soalnya adalah untuk menghitung kemungkinan langkah kuda untuk mencapai titik tujuan yang diinginkan 
*/
int minMove; 

void kuda(int move, int x, int y, int xTarget, int yTarget){
    if ( move > minMove ) return; // ketika dia udah lebih besar movenya daripada minMove yaudaa langsung aja return

    if ( x > 8 || x < 1 || y < 1 || y > 8 ) return; 

    if ( x == xTarget && y == yTarget ){
        if ( move < minMove ) minMove = move; 
    }

    kuda(move + 1, x+1, y+2, xTarget, yTarget); // 1 langkah ke kanan, dua langkah keatas dst
    kuda(move + 1, x+2, y+1, xTarget, yTarget); // 2 langkah kekanan, 1 langkah keatas
    kuda(move + 1, x+2, y-1, xTarget, yTarget); // 2 langkah kekanan, 1 langkah kebawah
    kuda(move + 1, x+1, y-2, xTarget, yTarget); // 1 langkah kekanan, 2 langkah kebawah 
    kuda(move + 1, x-1, y-2, xTarget, yTarget); // 1 langkah kekiri, 2 langkah kebawah
    kuda(move + 1, x-2, y-1, xTarget, yTarget); // 2 langkah kebawah, 1 langkah kekiri
    kuda(move + 1, x-2, y+1, xTarget, yTarget); // 2 langkah keiri, 1 langkah keatas 
    kuda(move + 1, x-1, y+2, xTarget, yTarget); // 1 langkah kekiri, 2 langkah keatas 
}       

int main(){
    int T; 
    scanf("%d", &T); 
    getchar(); 

    for ( int tc = 0; tc < T; tc++ ){
        char start[3]; 
        char end[3]; 
        scanf("%s %s", start, end); getchar(); 

        minMove = 100; // ini kenapa harus diinisialisasi sama 100?? idk 

        int chessBoard[10][10] = {0};
        int xStart = start[0] - 'A' + 1; // misal dia ada A - A = 0 + 1 = koordinat 1
        int xEnd = end[0] - 'A' + 1; // misal H - A = 7 + 1 = koordinat 8
        int yStart = start[1] - '0'; // misal ini 1 - 0 = 1 
        int yEnd = end[1] - '0'; // misal ini 8 - 0 = 8 

        kuda(0, xStart, yStart, xEnd, yEnd); 
        printf("Case #%d: ", tc+1);
        printf("%d\n", minMove); 
    } 
}