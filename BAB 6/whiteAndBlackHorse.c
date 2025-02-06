#include <stdio.h> 

int ketemu; 

void kuda(int moveCount, int maxMove, int x, int y, int xTarget, int yTarget){
	if ( ketemu ) return; 

	if ( x > 8 || x < 1 || y > 8 || y < 1 ){
		return; 
	}

	if ( x == xTarget && y == yTarget ){
		ketemu = 1; 
		return; 
	}

	if ( moveCount == maxMove ) return; 

	kuda(moveCount+1, maxMove, x+1, y+2, xTarget, yTarget); // 1 langkah ke kanan, dua langkah keatas dst
    kuda(moveCount+1, maxMove, x+2, y+1, xTarget, yTarget); // 2 langkah kekanan, 1 langkah keatas
    kuda(moveCount+1, maxMove, x+2, y-1, xTarget, yTarget); // 2 langkah kekanan, 1 langkah kebawah
    kuda(moveCount+1, maxMove, x+1, y-2, xTarget, yTarget); // 1 langkah kekanan, 2 langkah kebawah 
    kuda(moveCount+1, maxMove, x-1, y-2, xTarget, yTarget); // 1 langkah kekiri, 2 langkah kebawah
    kuda(moveCount+1, maxMove, x-2, y-1, xTarget, yTarget); // 2 langkah kebawah, 1 langkah kekiri
    kuda(moveCount+1, maxMove, x-2, y+1, xTarget, yTarget); // 2 langkah keiri, 1 langkah keatas 
    kuda(moveCount+1, maxMove, x-1, y+2, xTarget, yTarget); // 1 langkah kekiri, 2 langkah keatas 
}

int main(){
	int T; 
	scanf("%d", &T); 
	getchar(); 

	for ( int tc = 0; tc < T; tc++ ){
		int A; 
		scanf("%d", &A); 
		getchar(); 
		A = A * 2; 

		char start[3]; 
		char end[3]; 
		scanf("%s %s", start, end); 

		int chessBoard[10][10] = {0};
        int xStart = start[0] - 'A' + 1; // misal dia ada A - A = 0 + 1 = koordinat 1
        int xEnd = end[0] - 'A' + 1; // misal H - A = 7 + 1 = koordinat 8
        int yStart = start[1] - '0'; // misal ini 1 - 0 = 1 
        int yEnd = end[1] - '0'; // misal ini 8 - 0 = 8 

		ketemu = 0; // reset terus per testcase 

		kuda(0, A, xStart, yStart, xEnd, yEnd); 
		printf("Case #%d: ", tc+1); 
		if ( ketemu ) printf("YES\n"); 
		else printf("NO\n"); 
	}
}