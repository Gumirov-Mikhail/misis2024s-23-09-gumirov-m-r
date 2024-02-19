// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1200/A
// 1200A. Отельер

#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector <int> mas(10);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            for (int j = 0; j < mas.size(); j++) {
                if (mas[j] == 0) {
                    mas[j] = 1;
                    break;
                }
            }
        }
        else if (s[i] == 'R') {
            for (int j = 9; j >= 0; j--) {
                if (mas[j] == 0) {
                    mas[j] = 1;
                    break;
                }
            }
        }
        else {
            mas[s[i] - (int) '0'] = 0;
        }
    }
    for (int i = 0; i < mas.size(); i++) {
        std::cout << mas[i];
    }
    return 0;
}
