#include <stdio.h>
/*
    3
    2
    6
    8
*/

int main() {
    int t; 
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int min_animals = n / 4 + (n % 4 != 0 ? 1 : 0);
        
        printf("%d\n", min_animals);    
    }

    return 0;
}
