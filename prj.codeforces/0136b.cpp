// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/136/B
// 0136B. Троичная логика

#include <iostream>
#include <string>
#include <cmath>

std::string troich(int num) {
    std::string s;
    while (num > 0) {
        s += std::to_string(num % 3);
        num /= 3;
    }
    return s;
}

int desyat(const std::string& s) {
    int size = s.size();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int ch = s[i] - '0';
        sum += ch * pow(3, size - 1 - i);
    }
    return sum;
}

int main() {
    int a, c;
    std::cin >> a >> c;
    std::string tr_a = troich(a);
    std::string tr_c = troich(c);
    while (tr_a.size() != tr_c.size()) {
        if (tr_a.size() < tr_c.size()) {
            tr_a += '0';
        }
        else {
            tr_c += '0';
        }
    }
    //std::cout << tr_a << std::endl;
    //std::cout << tr_c << std::endl;
    int size = tr_a.size();
    std::string b_tr;
    for (int i = 0; i < size; i++) {
        int ch1 = tr_a[size - 1 - i] - '0';
        int ch2 = tr_c[size - 1 - i] - '0';
        //std::cout << ch1 << " " << ch2 << std::endl;
        if (ch1 < ch2) {
            b_tr += std::to_string(ch2 - ch1);
        }
        else if (ch1 == ch2) {
            b_tr += '0';
        }
        else {
            if (ch1 - ch2 == 2) {
                b_tr += '1';
            }
            else {
                b_tr += std::to_string((1 - ch2 + ch1) % 3);
            }
        }
    }
    //std::cout << b_tr << std::endl;
    std::cout << desyat(b_tr) << std::endl;
}