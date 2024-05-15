// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1873/C
// 1873C. Стрельба по мишени

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int k = 0; k < t; k++) {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                char cin;
                std::cin >> cin;
                if (cin == 'X') {
                    if (i == 1 || j == 1 || i == 10 || j == 10) {
                        sum += 1;
                    }
                    else if ((i >= 5 && j >= 5) && (i <= 6 && j <= 6)) {
                        sum += 5;
                    }
                    else if ((i >= 4 && j >= 4) && (i <= 7 && j <= 7)) {
                        sum += 4;
                    }
                    else if ((i >= 3 && j >= 3) && (i <= 8 && j <= 8)) {
                        sum += 3;
                    }
                    else if ((i >= 2 && j >= 2) && (i <= 9 && j <= 9)) {
                        sum += 2;
                    }
                }
            }
        }
        std::cout << sum << std::endl;
    }
}
