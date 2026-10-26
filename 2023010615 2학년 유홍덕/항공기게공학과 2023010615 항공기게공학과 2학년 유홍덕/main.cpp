#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int price, cnt, money;
    printf("단가 수량 받은금액: ");
    scanf("%d %d %d", &price, &cnt, &money);

    int pay = price * cnt * 9 / 10;   // 10% 할인한 결제 금액
    int c = money - pay;              // 거스름돈

    printf("결제 금액: %d원\n", pay);
    printf("거스름돈: %d원\n", c);
    printf("1000원권: %d장\n", c / 1000);
    printf("500원: %d개\n", c % 1000 / 500);
    printf("100원: %d개\n", c % 500 / 100);
    printf("50원: %d개\n", c % 100 / 50);

    return 0;
}