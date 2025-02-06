#include <stdio.h> 
#include <string.h> 

void search(char NIM[][11], char names[][21], int list, char target[]){
    for ( int i = 0; i < list; i++ ){
        if ( strcmp(NIM[i], target) == 0 ){
            printf("%s\n", names[i]); 
            return; 
        }
    }
    printf("N/A\n"); 
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N; 
    fscanf(file, "%d\n", &N); 

    char NIM[100][11]; // untuk nyimpen nimnya 
    char names[100][21]; // untuk nyimpen nama mahasiswa

    for ( int i = 0; i < N; i++ ){
        fscanf(file, "%s %s\n", NIM[i], names[i]); 
    }

    int M; 
    fscanf(file, "%d\n", &M); 

    for ( int tc = 0; tc < M; tc++ ){
        char targetNIM[11]; 
        fscanf(file, "%s\n", targetNIM); 

        printf("Case #%d: ", tc+1); 
        search(NIM, names, N, targetNIM); 
    }

    fclose(file); 
}