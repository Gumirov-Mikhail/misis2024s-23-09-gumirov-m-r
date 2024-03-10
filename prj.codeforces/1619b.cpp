// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1619/B
// 1619B. Квадраты и кубы

#include <iostream>
#include <cmath>
int main () {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int k = 1;
        int64_t n;
        std::cin >> n;
        int k3 = cbrt(n);
        int k2 = sqrt(n);
        int k6 = sqrt(cbrt(n));
        std::cout << k2 + k3 - k6 << std::endl;
    }
}