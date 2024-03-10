// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1077/A
// 1077A. Прыгающая лягушка

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int64_t a, b, c, d = 0;
        std::cin >> a >> b >> c;
        if (c % 2 == 0) {
            d += a * (c / 2);
            d -= b * (c / 2);
        }
        else {
            d += a * ((c / 2) + 1);
            d -= b * (c / 2);
        }
        std::cout << d << std::endl;
    }
}