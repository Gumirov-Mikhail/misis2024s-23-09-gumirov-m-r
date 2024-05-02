// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1054/A
// 1054A. Лифт или лестница?

#include <iostream>
#include <cstdlib>

int main() {
    int x, y, z, t1, t2, t3;
    std::cin >> x >> y >> z >> t1 >> t2 >> t3;
    int stairs = std::abs(x - y) * t1;
    int elevator_go_to_Masha = std::abs(x - z) * t2 + t3;
    int elevator_go_to_Egor = std::abs(x - y) * t2 + t3 * 2;
    int elevator = elevator_go_to_Masha + elevator_go_to_Egor;
    if (stairs < elevator) {
        std::cout << "NO" << std::endl;
    }
    else {
        std::cout << "YES" << std::endl;
    }
}