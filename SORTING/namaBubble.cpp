#include <stdio.h> 
#include <string.h>

/*
    suruh ngurutin nama berdasarkan abjad 
*/

void bubble_sort(char names[][50], int T){
    for ( int i = 0; i < T; i++ ){
        int swapped = 0; 
        for ( int j = 0; j < T - i - 1; j++ ){
            if ( strcmp(names[j], names[j+1] ) > 0){
                char temp[50]; 
                strcpy(temp, names[j]); 
                strcpy(names[j], names[j+1]); 
                strcpy(names[j+1], temp); 

                swapped = 1; 
            }
        }
        if ( !swapped ) break; 
    }
}

int main(){
    int T; 
    scanf("%d", &T); 

    char names[T][50]; 
    for ( int i = 0; i < T; i++ ){
        scanf("%s", &names[i]); 
    }

    bubble_sort(names, T); 

    for ( int i = 0; i < T; i++){
        printf("%s\n", names[i]); 
    }
}