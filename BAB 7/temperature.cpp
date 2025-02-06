#include <stdio.h> 
#include <string.h> 

void bubble_sort(char cityName[105][1005], char metric[105], double originalTemp[105], double convertedTemp[105], int n){
    for ( int i = 0; i < n - 1; i++ ){ // masalahnya disini - 1
        for ( int j = 0; j < n - i - 1; j++ ){
            if ( convertedTemp[j] > convertedTemp[j+1] || (convertedTemp[j] == convertedTemp[j+1] && strcmp(cityName[j], cityName[j+1]) > 0)){
                // Swap Suhu 
                double tempOriginal = originalTemp[j]; 
                double tempConverted = convertedTemp[j]; 
                originalTemp[j] = originalTemp[j+1]; 
                convertedTemp[j] = convertedTemp[j+1]; 
                originalTemp[j+1] = tempOriginal; 
                convertedTemp[j+1] = tempConverted; 

                // swap nama kota 
                char tempName[1005]; 
                strcpy(tempName, cityName[j]); 
                strcpy(cityName[j], cityName[j+1]); 
                strcpy(cityName[j+1], tempName); 

                // swap metric
                char tempMetric = metric[j]; 
                metric[j] = metric[j+1]; 
                metric[j+1] = tempMetric; 
            }
        }
    }
}

int main(){
    char cityName[105][1005]; // untuk menyimpan nama kotanya 
    char metric[105]; 
    double originalTemp[105]; // menyimpan suhu asli
    double convertedTemp[105]; // menympan setelah di konversi 

    int n = 0; 

    FILE *file = fopen("testdata.in", "r"); 

    while(fscanf(file,"%[^#]#%lf#%c\n", cityName[n], &originalTemp[n], &metric[n]) == 3 ){ // sama disini 
        if ( metric[n] == 'F'){
            convertedTemp[n] = ( originalTemp[n] - 32 ) * 5.0 / 9.0; 
        } else {
            convertedTemp[n] = originalTemp[n]; 
        }
        n++; 
    }

    fclose(file); 

    bubble_sort(cityName, metric, originalTemp, convertedTemp, n); 

    for ( int i = 0; i < n; i++ ){
        printf("%s is %.2lf%c\n", cityName[i], originalTemp[i], metric[i]); 
    }
}