// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/886/B
// 886B. Влад и столовые

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector <int> a(200005);
    for (int i = 1; i < n + 1; i++) {
        int el;
        std::cin >> el;
        a[el] = i;
    }
    int min = 2000000;
    int elnew = 0;
    for (int i = 0; i < 200005; i++) {
        if (a[i] != 0) {
            if (a[i] < min) {
                min = a[i];
                elnew = i;
            }
        }
    }
    std::cout << elnew << std::endl;
}
