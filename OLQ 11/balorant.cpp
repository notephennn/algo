#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

typedef struct {
    int rating; 
    char nama[105]; 
} Player;

const char* getLabel(int rating) {
    if (rating <= 200) {
        return "Ascend";
    } else if (rating <= 350) {
        return "Mortal";
    } else {
        return "Radial";
    }
}

int partition(Player players[], int low, int high) {
    Player pivot = players[high];
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {
        if (players[j].rating > pivot.rating || 
            (players[j].rating == pivot.rating && strcmp(players[j].nama, pivot.nama) < 0)) {
            i++;  
            Player temp = players[i];
            players[i] = players[j];
            players[j] = temp;
        }
    }
 
    Player temp = players[i + 1];
    players[i + 1] = players[high];
    players[high] = temp;

    return i + 1;
}

void quickSort(Player players[], int low, int high) {
    if (low < high) {
        int pi = partition(players, low, high);

        quickSort(players, low, pi - 1);
        quickSort(players, pi + 1, high);
    }
}

int main() {
    int P;
    scanf("%d", &P); 

    Player players[P]; 
    int totalRating = 0; 

    for (int i = 0; i < P; i++) {
        scanf("%d %s", &players[i].rating, players[i].nama);
        totalRating += players[i].rating;  
    }

    int averageRating = totalRating / P;

    quickSort(players, 0, P - 1);

    for (int i = 0; i < P; i++) {
        const char* label = getLabel(players[i].rating);
        int difference = players[i].rating - averageRating;
        printf("%s %d %d %s\n", label, players[i].rating, difference, players[i].nama);
    }

    return 0;
}
