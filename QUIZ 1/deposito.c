#include <stdio.h>

int main() {
    int M, N;      // M is the initial deposit, N is the number of months
    float I;       // I is the interest rate per annum

    // Input for M (initial deposit), N (number of months), I (interest rate per annum)
    printf("Enter initial deposit (M), number of months (N), and interest rate per annum (I):\n");
    scanf("%d %d %f", &M, &N, &I);

    // Loop for each month to calculate the interest and update the balance
    for (int month = 1; month <= N; month++) {
        // Calculate the interest for the month with 20% tax applied
        int monthlyInterest = (M * (I / 100.0) / 12.0) * 0.8;

        // Add the interest to the balance
        M += monthlyInterest;

        // Print the balance at the end of the current month
        printf("Month %d: %d\n", month, M);
    }

    return 0;
}

