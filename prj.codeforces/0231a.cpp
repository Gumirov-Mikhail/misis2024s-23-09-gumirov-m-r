// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/231/A
// 0231A. Команда

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int current;
            std::cin >> current;
            if (current == 1) {
                sum++;
            }
        }
        if (sum >= 2) {
            counter++;
        }
    }
    std::cout << counter;
}