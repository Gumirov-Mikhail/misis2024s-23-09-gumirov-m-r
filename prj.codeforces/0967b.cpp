// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/967/B
// 967B. Поливальная система

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int64_t n, A, B;
    std::cin >> n >> A >> B;
    std::vector <int> s(n-1);
    int el1;
    std::cin >> el1;
    int64_t sum = el1;
    for (int i = 0; i < n-1; i++) {
        int64_t sok;
        std::cin >> sok;
        s[i] = sok;
        sum += sok;
    }
    std::sort (s.begin(), s.end());
    int k = 0;
    for (int i = 0; i < n-1; i++) {
        if ((A * el1 / sum) >= B) {
            std::cout << k << std::endl;
            break;
        }
        k++;
        sum -= s[n-i-2];
    }
    if (k == (n - 1)) {
        std::cout << k << std::endl;
    }
    return 0;
}
