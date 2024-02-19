// 2023 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/1703/A
// 1703A. YES или YES?

#include <iostream>
#include <string>
#include <vector>
 
int main() {
    int n;
    std::cin >> n;
    std::vector <std::string> a(n);
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        s[0] = toupper(s[0]);
        s[1] = toupper(s[1]);
        s[2] = toupper(s[2]);
        a[i] = s;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == "YES") {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
