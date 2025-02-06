#include <stdio.h> 

void bubble_sort(long long arr[], int N){
    for ( int i = 0; i < N; i++ ){
        // int swapped = 0; 
        for ( int j = 0; j < N - 1; j++ ){
            if ( arr[j] > arr[j+1]){
                long long int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 

                // swapped = 1;     
            }
            // if ( !swapped ) break; 
        }
    }
}

int main(){
    FILE *file = fopen("testdata.in", "r"); 

    int N; 
    fscanf(file, "%d\n", &N); 

    long long int batang[105]; 
    for ( int i = 0; i < N; i++ ){
        fscanf(file, "%lld", &batang[i]); 
    }

    fclose(file); 

    bubble_sort(batang, N); 

    int flag = 0; 
    for (int i = 0; i < N - 2; i++) {
        if (batang[i] + batang[i + 1] > batang[i + 2]) {
            flag = 1; 
        }
    }

    if ( flag == 1 ) printf("YES\n");
    else printf("NO\n"); 
}