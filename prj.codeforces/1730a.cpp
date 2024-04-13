// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1730/A
// 1730A. Планеты

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, c;
        std::cin >> n >> c;
        std::set <int> tek;
        std::vector <int> mas(n);
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int a;
            std::cin >> a;
            tek.insert(a);
            mas[j] = a;
        }
        int h = tek.size();
        for (int j = 0; j < h; j++) {
            int l = *tek.begin();
            tek.erase(tek.begin());
            int key = std::count(mas.begin(), mas.end(), l);
            if (c > key) {
                sum += key;
            }
            else {
                sum += c;
            }
        }
        std::cout << sum << std::endl;
    }
}
