#include <stdio.h> 
#define MOD 1000000000

long long int weird_tree(int M, int N) {
    if (M == 0 || N <= 0) return 0; // Jika tinggi pohon 0, tidak ada cabang

    long long int currentBranches = N; // Jumlah cabang utama
    long long int totalBranches = 0; 
        
    totalBranches += (N - 1) * weird_tree(M - 1, N - 1) % MOD;
    totalBranches += weird_tree(M - 1, 1); // Satu cabang spesial yang memiliki 1 cabang
    long long int sum = totalBranches + currentBranches; 
    return sum % MOD; 
}

int main() {
    int T; 
    scanf("%d", &T); 

    for (int tc = 0; tc < T; tc++) {
        int M, N; // M = tinggi pohon, N = banyak cabang pohon 
        scanf("%d %d", &M, &N); 

        long long int totalBranches = weird_tree(M, N); 

        printf("Case #%d: %lld\n", tc + 1, totalBranches); 
    }

    return 0;
}
