#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

void bubble_sort(char name[][11], int score[], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++){
            if ( score[j] < score[j+1] || score[j] == score[j+1] && strcmp(name[j], name[j+1]) > 0 ){
                int tempScore = score[j]; 
                score[j] = score[j+1]; 
                score[j+1] = tempScore; 

                char tempName[11]; 
                strcpy(tempName, name[j]); 
                strcpy(name[j], name[j+1]); 
                strcpy(name[j+1], tempName); 

                tukar = 1; 
            }
        }
        if ( !tukar ) break; 
    }
}

int find_rank(char name[][11], int N, char target[]){
    for ( int i = 0; i < N; i++ ){
        if ( strcmp(name[i], target) == 0 ){
            return i + 1; 
        }
    }
    return -1; 
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; 
        scanf("%d", &N); getchar(); 

        char name[N+1][11]; 
        int score[N]; 

        for ( int i = 0; i < N; i++ ){
            scanf("%[^#]#%d\n", name[i], &score[i]); 
        }

        bubble_sort(name, score, N); 

        char target[11]; 

        scanf("%s", target); getchar(); // difungsikan buat masukkan nama ke indeks terakhir 

        int rank = find_rank(name, N, target); 

        printf("Case #%d: %d\n", tc+1, rank); 
    }
}