// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1950/C
// 1950C. Преобразование часов

#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if ((s[0] == '0' && s[1] >= '0') || (s[0] == '1' && s[1] < '2')) {
            if (s[0] == '0' && s[1] == '0') {
                s[0] = '1';
                s[1] = '2';
                std::cout << s << " " << "AM" << std::endl;
            }
            else {
                std::cout << s << " " << "AM" << std::endl;
            }
        }
        else {
            if (s[0] == '1' && s[1] == '2') {
                std::cout << s << " " << "PM" << std::endl;
            }
            else {
                if (s[1] == '1') {
                    s[1] = '9';
                    s[0] -= 2;
                }
                else if (s[1] == '0') {
                    s[1] = '8';
                    s[0] -= 2;
                }
                else {
                    s[1] -= 2;
                    s[0] -= 1;
                }
                std::cout << s << " " << "PM" << std::endl;
            }
        }
    }
}