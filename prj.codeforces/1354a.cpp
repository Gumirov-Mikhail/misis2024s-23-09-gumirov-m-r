// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1354/A
// 1354A. Будильник

#include <iostream>

int main () {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int64_t sum = b;
        if (sum >= a) {
            std::cout << sum;
        }
        else if (c <= d) {
            std::cout << -1;
        }
        else {
            if ((a - b) % (c - d) == 0) {
                sum += c * ((a - b) / (c - d));
            }
            else {
                sum += c * ((a - b) / (c - d) + 1);
            }
            std::cout << sum;
        }
       std::cout << std::endl; 
    }
}