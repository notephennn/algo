#include <stdio.h> 

int main(){
    int D, S, T; 
    scanf("%d %d %d", &D, &S, &T); 

    if (D>S && D>T){
        printf("Daging\n");
        if (S>T){
            printf("Sayur\nTelur\n");
        } else {
            printf("Telur\nSayur\n");
        }
    }
    else if (S>D && S>T){
        printf("Sayur\n");
        if (D>T){
            printf("Daging\nTelur\n");
        } else {
            printf("Telur\nDaging\n");
        }
    } 
    else if (T>D && T>S){
        printf("Telur\n");
        if (D>S){
            printf("Daging\nSayur\n");
        } else {
            printf("Sayur\nDaging\n");
        }
    }
    
    return 0;
}