// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/50/A
// 0050A. Сложение домино

#include <iostream>

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    int kol_poley = m*n;
    int counter = kol_poley/2;
    std::cout << counter;
}