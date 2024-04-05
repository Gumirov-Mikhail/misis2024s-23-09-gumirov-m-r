// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1850/B
// 1850B. Десять слов мудрости

#include <iostream>
#include <vector>
int main() {
    int t;
    std::cin >> t;
    std::vector <int> mas(t);
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int btek = 0;
        int chel = 0;
        for (int j = 0; j < n; j++) {
            int a, b;
            std::cin >> a >> b;
            if (a <= 10) {
                if (b > btek) {
                    btek = b;
                    chel = j + 1;
                }
            }
        }
        mas[i] = chel;
    }
    for (int i = 0; i < t; i++) {
        std::cout << mas[i] << std::endl;
    }
}