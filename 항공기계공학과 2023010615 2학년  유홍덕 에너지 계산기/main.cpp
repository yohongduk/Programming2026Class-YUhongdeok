#include <iostream>
using namespace std;

const double g = 9.81;

// 입력 함수: 0보다 클 때까지 다시 입력
double input(const char* name) {
    double x;
    do {
        cout << name << ": ";
        cin >> x;
        if (x <= 0) cout << "  -> Value must be positive. Enter again.\n";
    } while (x <= 0);
    return x;
}

// 출력 함수: 1000 J 이상이면 kJ도 함께 출력
void show(double e) {
    cout << "  Energy = " << e << " J";
    if (e >= 1000) cout << " (" << e / 1000 << " kJ)";
    cout << "\n";
}

// 자유낙하표: 높이를 5등분해서 6줄 출력
void table() {
    double m = input("Mass (kg)");
    double h0 = input("Start height (m)");
    cout << "  h(m)     PE(J)    KE(J)    Total(J)\n";
    for (int k = 0; k <= 5; k++) {
        double h = h0 - h0 / 5 * k;
        double pe = m * g * h;
        double ke = m * g * (h0 - h);
        cout << "  " << h << "  " << pe << "  " << ke << "  " << pe + ke << "\n";
    }
}

int main() {
    cout << fixed;
    cout.precision(3);

    int sel;
    do {
        cout << "\n=== Mechanical Energy Calculator ===\n"
            << "1. Kinetic energy  2. Potential energy  3. Free-fall table  0. Exit\n"
            << "Select: ";
        cin >> sel;

        if (sel == 1) {
            double m = input("Mass (kg)");
            double v = input("Speed (m/s)");
            show(0.5 * m * v * v);
        }
        else if (sel == 2) {
            double m = input("Mass (kg)");
            double h = input("Height (m)");
            show(m * g * h);
        }
        else if (sel == 3) table();
    } while (sel != 0);

    cout << "Exiting the program.\n";
}
