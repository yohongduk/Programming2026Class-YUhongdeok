#include <stdio.h>

int main() {
    int e, steps = 0, max;

    printf("Enter the initial engine energy: ");
    scanf_s("%d", &e);

    max = e;
    printf("Sequence: %d", e);

    while (e != 1) {
        if (e % 2 == 0)
            e = e / 2;
        else
            e = e * 3 + 1;

        steps = steps + 1;
        printf(" -> %d", e);

        if (e > max)
            max = e;
    }

    printf("\nEscape successful!\n");
    printf("Total steps: %d\n", steps);
    printf("Maximum altitude reached: %d\n", max);

    return 0;
}