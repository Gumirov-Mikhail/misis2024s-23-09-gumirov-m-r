// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/546/A
// 0546A. Солдат и бананы

#include <iostream>

int main() {
    int k, n, w;
    std::cin >> k >> n >> w;
    int sum = 0;
    for (int i = 0; i < w; i++) {
        sum += (i + 1) * k;
    }
    int ost = 0;
    if (sum >= n) {
        ost = sum - n;
    }
    std::cout << ost;
}
