#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("testdata.in", "r"); 

    int T;  
    fscanf(file, "%d\n", &T);

    char rsvpList[T][101];  
    for (int i = 0; i < T; i++) {
        fscanf(file, "%s", rsvpList[i]);
    } fgetc(file); 

    int N;
    fscanf(file, "%d\n", &N);

    for (int i = 0; i < N; i++) {
        char guestName[101];
        fscanf(file, "%s", guestName); fgetc(file); 

        int found = -1;
        for (int j = 0; j < T; j++) {
            if (strcmp(rsvpList[j], guestName) == 0) {
                found = j;
                break;
            }
        }

        printf("%d\n", found);
    }

    return 0;
}
