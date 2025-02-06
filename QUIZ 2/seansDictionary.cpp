#include <stdio.h>
#include <string.h>

/*
    10
    banana
    orange
    grape
    apple
    melon
    watermelon
    pear
    starfruit
    durian
    cherry
    3
    melon
*/

void swap(char A[], char B[]) {
    char temp[105];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
}

int partition(char daftarBuah[][105], int low, int high) {
    char pivot[105];
    strcpy(pivot, daftarBuah[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(daftarBuah[j], pivot) < 0) {
            i++;
            swap(daftarBuah[i], daftarBuah[j]);
        }
    }

    swap(daftarBuah[i + 1], daftarBuah[high]);
    return i + 1;
}

void quick_sort_recursion(char words[][105], int low, int high) {
    if (low < high) {
        int pi = partition(words, low, high);

        quick_sort_recursion(words, low, pi - 1);
        quick_sort_recursion(words, pi + 1, high);
    }
}

int find_page(char words[][105], int N, int pageSize, char target[]) {
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (strcmp(words[i], target) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return -1; 
    }

    return index / pageSize + 1; 
}

int main() {
    int N;
    scanf("%d", &N);

    char words[N][105];
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    int pageSize;
    scanf("%d", &pageSize);

    char target[105];
    scanf("%s", target);

    quick_sort_recursion(words, 0, N - 1);

    int page = find_page(words, N, pageSize, target);

    if (page == -1) {
        printf("Not Found\n");
    } else {
        printf("Found at %d\n", page);
    }

    return 0;
}
