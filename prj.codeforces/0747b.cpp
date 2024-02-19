// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/747/B
// 747B. Расшифровка генома мамонта

#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector <int> a(4);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a[0]++;
        }
        else if (s[i] == 'C') {
            a[1]++;
        }
        else if (s[i] == 'G') {
            a[2]++;
        }
        else if (s[i] == 'T') {
            a[3]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (a[0] < n / 4) {
                a[0]++;
                s[i] = 'A';
            }
            else if (a[1] < n / 4) {
                a[1]++;
                s[i] = 'C';
            }
            else if (a[2] < n / 4) {
                a[2]++;
                s[i] = 'G';
            }
            else if (a[3] < n / 4){
                a[3]++;
                s[i] = 'T';
            }
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            k = 1;
            break;
        }
    }
    for (int j = 0; j < 4; j ++) {
        if (a[j] > n / 4) {
            k = 1;
            break;
        }
    }
    if (k == 0) {
        std::cout << s << std::endl;
    }
    else {
        std::cout << "===" << std::endl;
    }
}
