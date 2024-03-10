// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1418/A
// 1418A. Покупка факелов

#include <iostream>
#include <string>
 
 
int main(){
  int64_t t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int64_t x,y,k;
    std::cin >> x >> y >> k;
    std::cout << ((y + 1) * k - 1 + x - 2) / (x - 1) + k << "\n";
  }
  
  std::cout << std::endl;
}