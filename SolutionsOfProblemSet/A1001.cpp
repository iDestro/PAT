/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-05-28 09:32:45
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-31 18:42:11
 */
#include <iostream>
#include <stack>
using namespace std;
int main() {
    long long a, b;
    cin >> a >> b;
    stack<char> S;
    long long c = a + b;
    if (c == 0) {
        cout << 0;
        return 0;
    }
    bool isNeg = false;
    if (c < 0) {
        c = -c;
        isNeg = true;
    }
    int cnt = 1;
    while (c != 0) {
        S.push(c % 10 + '0');
        if (cnt % 3 == 0 && c / 10 != 0) {
            S.push(',');
        }
        cnt++;
        c /= 10;
    }
    if (isNeg) {
        cout << "-";
    }
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    return 0;
}