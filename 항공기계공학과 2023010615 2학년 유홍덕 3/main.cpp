#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int sec;
    printf("Enter the total time in seconds: ");
    scanf("%d", &sec);

    int h = sec / 3600;       
    int m = sec % 3600 / 60;   
    int s = sec % 60;         

    printf("%d seconds are %d hours %d minutes %d seconds.\n", sec, h, m, s);
    printf("Digital notation: %02d:%02d:%02d\n", h, m, s);

    return 0;
}