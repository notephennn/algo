#include <stdio.h> 
#include <string.h> 

/*
    4 
    algebra 7 
    english 7 
    algo 3 
    pdm 5
*/

void bubble_sort(long long int dates[], char matkul[][11], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( dates[j] > dates[j+1] || dates[j] == dates[j+1] && strcmp(matkul[j], matkul[j+1]) > 0 ){
                long long int tempDate = dates[j]; 
                dates[j] = dates[j+1]; 
                dates[j+1] = tempDate; 

                char tempMatkul[11]; 
                strcpy(tempMatkul, matkul[j]); 
                strcpy(matkul[j], matkul[j+1]); 
                strcpy(matkul[j+1], tempMatkul); 

                tukar = 1; 
            }
        }
        if( !tukar ) break; 
    }
}

int main(){
    int N; 
    scanf("%d", &N); 

    long long int dates[105]; 
    char matkul[100][11]; 

    for ( int i = 0; i < N; i++ ){
        scanf("%s %lld", matkul[i], &dates[i]); 
    }

    bubble_sort(dates, matkul, N); 

    for ( int i = 0; i < N; i++){
        printf("%s\n", matkul[i]); 
    }
}