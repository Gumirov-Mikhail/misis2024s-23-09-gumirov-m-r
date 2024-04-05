// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1850/D
// 1850D. Сбалансированный раунд

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    std::vector <int> otv(t);
    for (int i = 0; i < t; i++) {
        long long int n, k;
        std::cin >> n >> k;
        std::vector <int> mas(n);
        for (int j = 0; j < n; j++) {
            int ch;
            std::cin >> ch;
            mas[j] = ch;
        }
        sort(mas.begin(), mas.end());
        int kol = 0;
        int kolpr = 0;
        for (int j = 0; j < n - 1; j++) {
            if (mas[j+1] - mas[j] <= k) {
                kol++;
            }
            else {
                if (kol > kolpr) {
                    kolpr = kol;
                }
                kol = 0;
            }
        }
        if (kol > kolpr) {
            kolpr = kol;
        }
        otv[i] = n - 1 - kolpr;
    }
    for (int i = 0; i < t; i++) {
        std::cout << otv[i] << std::endl;
    }
}