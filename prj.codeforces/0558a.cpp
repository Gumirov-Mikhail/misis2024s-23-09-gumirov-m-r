// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/558/A
// 0558A. Duff и мясо

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int minst = 10000;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int kol, st;
        std::cin >> kol >> st;
        if (st < minst) {
            minst = st;
        }
        sum += (minst * kol);
    }
    std::cout << sum;
}