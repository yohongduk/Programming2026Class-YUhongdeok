#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int price(int s)   // Drink price
{
    if (s == 1) return 1200;   // Cola
    if (s == 2) return 1100;   // Cider
    return 800;                // Coffee
}

int main(void)
{
    int s, coin, cnt = 0, sales = 0;

    while (1) {
        printf("===== Drink Vending Machine =====\n");
        printf("1. Cola(1200 won)  2. Cider(1100 won)  3. Coffee(800 won)  0. Exit\nSelect: ");
        scanf("%d", &s);
        if (s == 0) break;
        if (s < 0 || s > 3) continue;

        int p = price(s), money = 0;
        while (money < p) {
            printf("Insert (Current %d won / Need %d won): ", money, p);
            scanf("%d", &coin);
            if (coin == 100 || coin == 500 || coin == 1000) money += coin;
            else printf("  -> %d won cannot be used.\n", coin);
        }

        int c = money - p;   // Change
        printf("Your drink is ready! Change: %d won\n  500 won: ", c);
        for (int i = 0; i < c / 500; i++) printf("o");
        printf("\n  100 won: ");
        for (int i = 0; i < c % 500 / 100; i++) printf("o");
        printf("\n\n");

        cnt++;
        sales += p;
    }

    printf("Today's sales: %d drinks, Revenue: %d won\n", cnt, sales);
    return 0;
}