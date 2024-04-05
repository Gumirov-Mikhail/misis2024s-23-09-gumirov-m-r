// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1850/C
// 1850C. Слово на бумаге

#include <iostream>
#include <vector>
#include <string>
int main() {
    int t;
    std::cin >> t;
    std::vector <std::string> mas(t);
    for (int i = 0; i < t; i++) {
        std::string s = "";
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                char tochka;
                std::cin >> tochka;
                if (tochka >= 'a' && tochka <= 'z') {
                    s += tochka;
                }
            }
        }
        mas[i] = s;
    }
    for (int i = 0; i < t; i++) {
        std::cout << mas[i] << std::endl;
    }
}