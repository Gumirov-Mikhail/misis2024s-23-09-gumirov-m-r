// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/339/B
// 0339B. Ксюша и кольцевая дорога

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    long long sum = 0;
    int t;
    std::cin >> t;
    sum += (t-1);
    for (int i = 1; i < m; i++) {
        int cur;
        std::cin >> cur;
        if (cur >= t) {
            sum += (cur - t);
        }
        else {
            if (cur >= n) {
                sum += (cur - t);
            }
            else {
                sum += (n - t);
                sum += cur;
            }
        }
        t = cur;
    }
    std::cout << sum;
}
