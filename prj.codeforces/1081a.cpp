// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1081/A
// 1081A. Определенная игра

#include <iostream>

int main () {
    int64_t x;
    std::cin >> x;
    while (x > 2) {
        for (int i = x - 1; i > 1; i--) {
            if (x % i != 0 && x - i > 0) {
                x -= i;
                break;
            }
        }
    }
    std::cout << x << std::endl;
}