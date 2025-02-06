#include <stdio.h>
#include <string.h> 

/*
    10 
    Aaliyah#Fragaria 
    Briana#Quisqualis indica 
    Cameron#Bomabaceae 
    Daphne#Calodendrum capanse 
    Davina#Anthemis nobilis 
    Elsa#Cola acuminata 
    Fiona#Dracaena fragrans 
    Gwen#Fraxinus americana 
    Helen#Gazania 
    Irene#Gerberajamesonii 
    5 
    Aaliyah 
    Irene 
    Davina 
    Elsa 
    Zacky
*/

int plantIndex(char names[][45], char plants[][45], int N, char target[]) {
    for (int i = 0; i < N; i++) {
        if (strcmp(names[i], target) == 0)
            return i;
    }
    return -1;
}


int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N; 
    fscanf(file, "%d\n", &N); 

    char name[105][45]; 
    char plants[105][45]; 

    for ( int i = 0; i < N; i++ ){
        fscanf(file, "%[^#]#%[^\n]\n", name[i], plants[i]); 
    }

    int M; 
    fscanf(file, "%d\n", &M); 

    for ( int i = 1; i <= M; i++ ){
        char target[45]; 
        fscanf(file, "%[^\n]\n", target); 

        int index = plantIndex(name, plants, N, target); 

        printf("Case #%d: ", i); 
        if ( index == -1 ) printf("N/A\n"); 
        else printf("%s\n", plants[index]); 

    }

    fclose(file); 
}