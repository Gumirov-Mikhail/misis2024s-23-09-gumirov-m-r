// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/768/A
// 1017A. Место в таблице

#include <vector>
#include <iostream>
#include <algorithm>

int main () {
    int n;
    std::cin >> n;
    std::vector <int> mas;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        mas.push_back(sum);
    }
    int dj = mas[0];
    std::sort(mas.begin(), mas.end());
    for (int i = n-1; i >= 0; i--) {
        if (mas[i] == dj) {
            std::cout << n - i;
            break;
        }
    }
}
