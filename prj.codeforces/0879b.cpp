// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/879/B
// 879B. Настольный теннис

#include <iostream>
int main() {
    long long int n, k, x, m = 0, y;
    std::cin >> n >> k >> x;
    for (int i = 1; i < n; i++) {
        std::cin >> y;
        if (m == k) {
            break;
        }
        if (x > y) {
            m++;
        }
        else {
            x = y;
            m = 1;
        }
    }
    std::cout << x << std::endl ;
}