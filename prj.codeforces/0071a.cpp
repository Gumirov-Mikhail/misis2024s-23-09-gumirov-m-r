// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/71/A
// 0071A. Слишком длинные слова

#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (s.size() > 10) {
            std::cout << s[0] << s.size()-2 << s[s.size()-1] << std::endl;
        }
        else {
            std::cout << s << std::endl;
        }
    }
}