// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/41/A
// 0041A. Перевод

#include <iostream>
#include <string>

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    if (s1.size() == s2.size()) {
        bool flag = false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[s1.size()-1-i]) {
                std::cout << "NO";
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << "YES";
        }
    }
    else {
        std::cout << "NO";
    }
}