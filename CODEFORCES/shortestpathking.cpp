#include <stdio.h> 
#include <limits.h> 
#include <MATH.H> 
#define BOARD_SIZE 8

int isValid( int X, int Y ){
    return ( X >= 0 && X < BOARD_SIZE && Y >= 0 && Y < BOARD_SIZE);
}

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int min_moves(int startX, int startY, int targetX, int targetY, int moves, int best){
    if ( startX == targetX && startY == targetY ) return moves; 

    if ( moves >= best ) return best; 

    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1}; 
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1}; 

    int min_move_count = best;  

    for ( int i = 0; i < 8; i++ ){
        int newX = startX + dx[i]; 
        int newY = startY + dy[i]; 

        if ( isValid(newX, newY) && manhattan_distance(newX, newY, targetX, targetY) < manhattan_distance(startX, startY, targetX, targetY)){
            int result = min_moves(newX, newY, targetX, targetY, moves+1, min_move_count);  
            if ( result < min_move_count) min_move_count = result; 
        }
    }

    return min_move_count; 
}

void converted_board( char coordinate[], int *X, int *Y){
    *X = coordinate[0] - 'a'; 
    *Y = coordinate[1] - '1'; 
}

int main(){
    char start[3], end[3]; 
    int startX, startY, targetX, targetY; 

    scanf("%s", start);   
    scanf("%s", end); 

    converted_board(start, &startX, &startY);
    converted_board(end, &targetX, &targetY);

    int result = min_moves(startX, startY, targetX, targetY, 0, INT_MAX);
    printf("%d\n", result); 
}