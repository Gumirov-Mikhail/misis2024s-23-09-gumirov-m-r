// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1873/D
// 1873D. 1D Ластик

#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        int counter = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'B') {
                j += (m-1);
                counter++;
            }
        }
        std::cout << counter << std::endl;
    }
}
