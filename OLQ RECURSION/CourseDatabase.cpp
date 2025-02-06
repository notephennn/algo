#include <stdio.h> 
#include <string.h> 

/*
    3
    COMP6047
    Algorithm and Programming 
    6
    COMP6056
    Program Design Methods
    4
    MATH6025
    Discrete Mathematics
    4
    3
    3
    2
    1
*/

void swap(int *a, int *b, char code[][20], char name[][100], int index1, int index2){
    int temp = *a; 
    *a = *b; 
    *b = temp; 

    char tempCode[20]; 
    char tempName[100]; 

    strcpy(tempCode, code[index1]); 
    strcpy(code[index1], code[index2]); 
    strcpy(code[index2], tempCode); 

    strcpy(tempName, name[index1]); 
    strcpy(name[index1], name[index2]); 
    strcpy(name[index2], tempName); 

}

void bubble_sort(int credit[], int N, char code[][20], char name[][100]){
    for ( int i = 0; i < N; i++){
        int swapped = 0; 
        for ( int j = 0; j < N - i - 1; j++){
            if ( credit[j] > credit[j+1]){
                swap(&credit[j], &credit[j+1], code, name, j, j+1); 
            }
            else if ( credit[j] == credit[j+1] && strcmp(name[j], name[j+1]) > 0 ){
                swap(&credit[j], &credit[j+1], code, name, j, j+1); 
            }
        }
    }
}

int main(){
    int T; 
    scanf("%d", &T); getchar(); 

    char code[100][20]; 
    char name[100][100]; 
    int credits[100];
    int order[100];  

    for ( int tc = 0; tc < T; tc++){
        scanf("%[^\n]", code[tc]); getchar(); 
        scanf("%[^\n]", name[tc]); getchar(); 
        scanf("%d", &credits[tc]); getchar(); 
    }

    for (int i = 0; i < T; i++) {
        scanf("%d", &order[i]); // Membaca urutan kredit
    }

    bubble_sort(credits, T, code, name); 

    for ( int i = 0; i < T; i++ ){
        int index = order[i] - 1; 
        printf("Case #%d:\n", i+1); 
        printf("Code: %s\n", code[index]); 
        printf("Name: %s\n", name[index]); 
        printf("Credit: %d\n", credits[index]); 
    }
}