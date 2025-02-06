#include <stdio.h>
#include <string.h> 

/*
    BeeTubeRewind2019#EttaKelelawar#10000 
    LaguNasionalis#EkoGustiwono#2500 
    MakanSambel#RensEntertainment#5000 
    SelamatTinggal#LucintaLama#7500 
    AyoOlahraga#NusaRoro#2500
*/

void bubble_sort(char title[][1005], char name[][1005], int views[100], int N){
    for ( int i = 0; i < N; i++ ){
        int tukar = 0; 
        for ( int j = 0; j < N - i - 1; j++ ){
            if ( views[j] < views[j+1] || views[j] == views[j+1] && strcmp(title[j], title[j+1]) > 0 ){
                int tempViews = views[j]; 
                views[j] = views[j+1]; 
                views[j+1] = tempViews; 

                char tempTitle[1005]; 
                strcpy(tempTitle, title[j]); 
                strcpy(title[j], title[j+1]); 
                strcpy(title[j+1], tempTitle); 

                char tempNama[1005]; 
                strcpy(tempNama, name[j]); 
                strcpy(name[j], name[j+1]); 
                strcpy(name[j+1], tempNama); 

                tukar = 1; 
            }
        }
        if ( !tukar ) break; 
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    char title[100][1005]; 
    char name[100][1005]; 
    int views[100]; 

    int N = 0; 

    while (!feof(file)) {
        int scanfile = fscanf(file, "%[^#]#%[^#]#%d\n", title[N], name[N], &views[N]); 

        if (scanfile == 3) { // Jika pembacaan 3 field berhasil 
            N++; 
        } else {
            break; // Hentikan jika pembacaan gagal
        }
    }

    bubble_sort(title, name, views, N); 

    for ( int i = 0; i < N; i++ ){
        printf("%s by %s - %d\n", title[i], name[i], views[i]); 
    }

    fclose(file); 
}