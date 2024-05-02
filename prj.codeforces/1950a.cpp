// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1950/A
// 1950A. Ступенька, Пик или ни то, ни другое?

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a < b && b < c) {
            std::cout << "STAIR" << std::endl;
        }
        else if (a < b && b > c) {
            std::cout << "PEAK" << std::endl;
        }
        else {
            std::cout << "NONE" << std::endl;
        }
    }
}