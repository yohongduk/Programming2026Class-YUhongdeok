#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rate(int t)   // Function to get discount rate
{
    if (t == 1) return 50;   // Compact car
    if (t == 3) return 30;   // Electric car
    if (t != 2) printf("  -> Regular rate applied\n");
    return 0;                // Regular
}

int main(void)
{
    int n, t, m, total = 0, max = -1, car = 0;

    printf("Number of cars to settle(1-10): ");
    scanf("%d", &n);
    while (n < 1 || n > 10) {
        printf("  -> Please enter between 1-10.\nNumber of cars to settle(1-10): ");
        scanf("%d", &n);
    }

    for (int i = 1; i <= n; i++) {
        printf("\n[Car %d]\nType(1:Compact 2:Regular 3:Electric): ", i);
        scanf("%d", &t);
        printf("Parking time(min): ");
        scanf("%d", &m);
        while (m < 0) {
            printf("  -> Enter 0 or more again: ");
            scanf("%d", &m);
        }

        int fee = 0, r = rate(t);
        if (m > 30) fee = (m - 21) / 10 * 500;   // Fee calculation
        if (fee > 20000) fee = 20000;            // Max 20000 won
        fee = fee * (100 - r) / 100;             // Discount
        printf("  Fee: %d won (Discount %d%%)\n", fee, r);

        total += fee;
        if (fee > max) { max = fee; car = i; }
    }

    printf("\nTotal amount: %d won\nHighest fee: Car %d (%d won)\n", total, car, max);
    return 0;
}