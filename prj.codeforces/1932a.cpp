// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1932/A
// 1932A. Шипы и монеты

#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int counter = 0;
        char pred = s[0];
        for (int j = 1; j < n; j++) {
            char tek = s[j];
            if (tek == '@') {
                counter++;
            }
            else if (tek == '*' && pred == '*') {
                break;
            }
            pred = tek;
        }
        std::cout << counter << std::endl;
    }
}