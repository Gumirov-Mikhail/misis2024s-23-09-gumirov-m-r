// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/768/A
// 768A. Клятва Ночного дозора

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int k = 0;
    int max = a[n-1];
    int min = a[0];
    for (int i = 1; i + 1 < n; ++i) {
        if ((a[i] > min) && (a[i] < max)) {
            k++;
        }
    }
    std::cout << k;
    return 0;
}
