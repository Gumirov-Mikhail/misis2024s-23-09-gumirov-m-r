// 2024 by Gumirov Mikhail
// task source https://codeforces.com/problemset/problem/767/A
// 767A. Снековик

#include <array>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnd[n];
    priority_queue<int> p;
    string t = "";
    int last_add = n + 1;
    for (int i = 0; i < n; i++) {
        t = "";
        cin >> cnd[i];
        p.push(cnd[i]);
        while (p.top() == last_add - 1) {
            t += to_string(p.top()) + ' ';
            last_add = p.top();
            p.pop();
        }
        cout << t << endl;
    }
}
