#include <stdio.h>
#include <string.h>

/* Pak Saya sudah menggunakan quick dan selection sortt */

typedef struct {
    char nama[1005];
    int J, P;   
} people;

void selection_sort(people daftarPeople[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < N; j++) {
            int currentTotal = daftarPeople[j].J * daftarPeople[j].P;
            int maxTotal = daftarPeople[maxIndex].J * daftarPeople[maxIndex].P;

            if (currentTotal > maxTotal) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            people temp = daftarPeople[i];
            daftarPeople[i] = daftarPeople[maxIndex];
            daftarPeople[maxIndex] = temp;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N); 

    people daftarPeople[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", daftarPeople[i].nama, &daftarPeople[i].J, &daftarPeople[i].P);
    }

    selection_sort(daftarPeople, N);

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", daftarPeople[i].nama, daftarPeople[i].J * daftarPeople[i].P);
    }

    return 0;
}
