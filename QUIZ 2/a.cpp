#include <stdio.h>
#include <string.h>

/*
    3
    Harry 4 50
    Hermione 3 40
    Ron 2 110

    Output: 
    Ron 220
    Harry 200
    Hermione 120
*/

typedef struct {
    char nama[1005];
    int J, P;
} people;

void swap(people *a, people *b) {
    people temp = *a;
    *a = *b;
    *b = temp;
}

int partition(people daftarPeople[], int low, int high) {
    people pivot = daftarPeople[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((daftarPeople[j].J * daftarPeople[j].P) > (pivot.J * pivot.P)) {
            i++;
            swap(&daftarPeople[i], &daftarPeople[j]);
        } else if ((daftarPeople[j].J * daftarPeople[j].P) == (pivot.J * pivot.P)) {
            if (strcmp(daftarPeople[j].nama, pivot.nama) < 0) {
                i++;
                swap(&daftarPeople[i], &daftarPeople[j]);
            }
        }
    }

    swap(&daftarPeople[i + 1], &daftarPeople[high]);
    return i + 1;
}

void quick_sort_recursion(people daftarPeople[], int low, int high) {
    if (low < high) {
        int pi = partition(daftarPeople, low, high);

        quick_sort_recursion(daftarPeople, low, pi - 1);
        quick_sort_recursion(daftarPeople, pi + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    people daftarPeople[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", daftarPeople[i].nama, &daftarPeople[i].J, &daftarPeople[i].P);
    }

    quick_sort_recursion(daftarPeople, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", daftarPeople[i].nama, daftarPeople[i].J * daftarPeople[i].P);
    }

    return 0;
}
