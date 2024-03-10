// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1143/A
// 1143A. The Doors

#include <iostream>

int main () {
    int n;
    std::cin >> n;
    int k0 = 0;
    int k1 = 1;
    int el0 = 0;
    int el1 = 0;
    for (int i = 1; i <= n; i++) {
        int m;
        std::cin >> m;
        if (m == 0) {
            k0++;
            el0 = i;
        }
        else {
            k1++;
            el1 = i;
        }
    }
    if (n - el0 > n - el1) {
        std::cout << el0 << std::endl;
    }
    else {
        std::cout << el1 << std::endl;
    }
}