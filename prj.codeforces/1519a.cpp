// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1519/A
// 1519A. Красные и синие мармеладки

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  for (int j = 0; j < t; ++j) {
    int64_t a, b, d;
    std::cin >> a >> b >> d;
    if (a > b) {
      std::swap(a, b);
    }
    if (a * (d + 1) >= b) {
      std::cout << "Yes";
    }
    else {
      std::cout << "No";
    }
    std::cout << std::endl;
  }
}