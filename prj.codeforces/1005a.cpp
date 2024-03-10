// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1005/A
// 1005A. Таня и лестницы

#include <iostream>
#include <vector>
int main () {
    int t;
    std::cin >> t;
    int k = 1;
    int a;
    std::vector <int> mas;
    std::cin >> a;
    for (int i = 1; i < t; i++) {
        int a1;
        std::cin >> a1;
        if (a1 == 1) {
            k++;
            mas.push_back(a);
        }
        a = a1;
    }
    mas.push_back(a);
    std::cout << k << std::endl;
    for (int i = 0; i < mas.size(); i++) {
        std::cout << mas[i] << " ";
    }
}