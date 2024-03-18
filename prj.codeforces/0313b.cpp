// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/313/B
// 0313B. Илья и запросы

#include <iostream>
#include <string>
#include <vector>

int main () {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::vector <int> mas(s.length());
    mas[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            mas[i] = mas[i-1] + 1;
        }
        else {
            mas[i] = mas[i-1];
        }
    }
    for (int i = 0; i < n; i++) {
        int lhs, rhs;
        std::cin >> lhs >> rhs;
        std::cout << mas[rhs-1] - mas[lhs-1] << std::endl;
    }
}