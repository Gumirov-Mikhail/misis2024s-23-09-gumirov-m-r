// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/4/A
// 0004A. Арбуз

#include <iostream>

int main() {
    int w;
    std::cin >> w;
    if (w > 3) {
        std::cout << ((w % 2 == 0) ? "YES" : "NO");
    }
    else {
        std::cout << "NO";
    }
}