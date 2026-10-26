#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define POTION 1000
#define SCROLL 2000
#define ELIXIR 3000

int main()
{
    int money = 0, pick = 0, price = 0, count = 0;
    const char* name = "";

    printf("Insert coins (Current Balance): ");
    scanf("%d", &money);

    while (1)
    {
        printf("\n--- Goblin's Vending Machine ---\n");
        printf("1. Red Potion (%d G)\n", POTION);
        printf("2. Magic Scroll (%d G)\n", SCROLL);
        printf("3. Elixir (%d G)\n", ELIXIR);
        printf("0. Exit\n");
        printf("----------------------------------------\n");
        printf("Select an item: ");
        scanf("%d", &pick);

        if (pick == 0)
        {
            printf("Returning %d G. Goodbye!\n", money);
            break;
        }

        if (pick == 1) { price = POTION; name = "Red Potion"; }
        else if (pick == 2) { price = SCROLL; name = "Magic Scroll"; }
        else if (pick == 3) { price = ELIXIR; name = "Elixir"; }
        else
        {
            printf("Wrong number!\n");
            continue;
        }

        if (count % 3 == 2)
        {
            price = price / 2;
            printf("*** GOBLIN'S BLESSING! 50%% DISCOUNT! ***\n");
        }

        if (money < price)
        {
            printf("Not enough balance!\n");
            continue;
        }

        count++;
        money = money - price;
        printf("[Purchased] %s for %d G. Balance: %d G\n", name, price, money);
    }

    return 0;
}