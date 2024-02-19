// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/520/A
// 520A. Панграмма

#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector <int> d(26);
    for (int i = 0; i < n; i++) {
        s[i] = toupper(s[i]);
        d[(int) s[i] - ((int) 'A')]++;
    }
    int flag = 0;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] < 1) {
            std::cout << "NO";
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        std::cout << "YES";
    }
    return 0;
}
