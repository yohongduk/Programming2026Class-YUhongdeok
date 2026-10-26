#include <iostream>
#include <iomanip>
#include <windows.h>
#pragma execution_character_set("utf-8")
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    int c, t, p, n, paid;
    while (cout << "\n1.시간변환 2.거스름돈 0.종료: ", cin >> c && c)
    {
        if (c == 1)
        {
            cout << "총 시간을 초 단위로 입력하세요: ";  cin >> t;
            cout << t << "초는 " << t / 3600 << "시간 " << t % 3600 / 60 << "분 " << t % 60 << "초입니다.\n디지털 표기: "
                << setfill('0') << setw(2) << t / 3600 << ':' << setw(2) << t % 3600 / 60 << ':' << setw(2) << t % 60 << setfill(' ') << '\n';
        }
        else if (c == 2)
        {
            cout << "상품 단가(원): ";  cin >> p;
            cout << "수량(개): ";       cin >> n;
            int sum = p * n, pay = sum - sum / 10;
            cout << "합계 금액 : " << sum << "원\n할인(10%) : -" << sum / 10 << "원\n결제 금액 : " << pay << "원\n받은 금액(원): ";
            cin >> paid;
            int ch = paid - pay;
            if (ch < 0) { cout << -ch << "원 부족\n"; continue; }
            cout << "거스름돈 : " << ch << "원\n";
            for (int u : { 1000, 500, 100, 50 }) { cout << setw(5) << u << "원 : " << ch / u << (u == 1000 ? "장\n" : "개\n");  ch %= u; }
            cout << "  나머지 : " << ch << "원\n";
        }
    }
}