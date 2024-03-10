// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1385/A
// 1385A. Три попарных максимума

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int64_t x, y, z;
        std::cin >> x >> y >> z;
        int64_t a, b, c;
        if (x >= y && x >= z && (x == y || x == z)) {
            if (y > z) {
                std::cout << "YES" << std::endl;
                std::cout << x << " " << z << " " << z << std::endl;
            }
            else {
                std::cout << "YES" << std::endl;
                std::cout << x << " " << y << " " << y << std::endl;
            }
        }
        else if (y >= x && y >= z && (y == x || y == z)) {
            if (x > z) {
                std::cout << "YES" << std::endl;
                std::cout << y << " " << z << " " << z << std::endl;
            }
            else {
                std::cout << "YES" << std::endl;
                std::cout << y << " " << x << " " << x << std::endl;
            }
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}