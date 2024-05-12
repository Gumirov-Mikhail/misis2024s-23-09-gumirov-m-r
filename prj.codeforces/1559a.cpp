// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1559/A
// 1559A. Мокко и математика

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<long long> vec(n);
        for (int j = 0; j < n; j++) {
            std::cin >> vec[j];
        }
        long long min = 1000000000;
        long long first = vec[0];
        for (int j = 0; j < n; j++) {
            first &= vec[j];
            if (first < min) {
                min = first;
            }

        }
        std::cout << min << std::endl;
    }
}