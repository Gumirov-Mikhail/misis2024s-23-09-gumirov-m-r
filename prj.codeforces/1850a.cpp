// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1850/A
// 1850A. To My Critics

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a + b >= 10) {
            std::cout << "YES" << std::endl;
        }
        else if (c + b >= 10) {
            std::cout << "YES" << std::endl;
        }
        else if (a + c >= 10) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}