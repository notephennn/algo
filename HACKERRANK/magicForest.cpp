#include <stdio.h>

int findStepsRecursive(int tree[], int n, int index, int currentSum, int target, int steps) {
    if (index >= n) return -1; // Jika simpul di luar batas, tidak valid
    currentSum += tree[index];

    if (currentSum == target) return steps; // Jika ditemukan target, kembalikan langkah

    int left = findStepsRecursive(tree, n, 2 * index + 1, currentSum, target, steps + 1);
    if (left != -1) return left; // Jika ditemukan di anak kiri, kembalikan hasil

    return findStepsRecursive(tree, n, 2 * index + 2, currentSum, target, steps + 1);
}

void solveCase(int tree[], int n, int target, int caseNum) {
    int result = findStepsRecursive(tree, n, 0, 0, target, 0);
    if (result != -1) {
        printf("Case #%d: %d\n", caseNum, result);
    } else {
        printf("Case #%d: -1\n", caseNum);
    }
}

int main() {
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++) {
        int N, target;
        scanf("%d", &N);

        int tree[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &tree[i]);
        }

        scanf("%d", &target); 

        solveCase(tree, N, target, tc + 1);
    }

    return 0;
}
