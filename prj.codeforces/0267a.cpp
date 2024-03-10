// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/267/A
// 0267A. Вычитания

#include <iostream>

int main () {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t a, b;
        std::cin >> a >> b;
        int64_t k = 0;
        while (a > 0 && b > 0) {
            if (a > b) {
                int d = a / b;
                a -= (d * b);
                k += d;
            }
            else {
                int d = b / a;
                b -= (d * a);
                k += d;
            }
        }
        std::cout << k << std::endl;
    }
}