/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-13 22:41:01
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-13 23:04:12
 */
#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b) {
    if (a.length() < b.length()) {
        swap(a, b);
    }
    int i = a.length()-1, j = b.length()-1, carry = 0;
    while (j >= 0) {
        int s = a[i]+b[i] + carry - 2*'0';
        carry = s / 10;
        a[i] = s % 10 + '0';
        j--;
        i--;
    }
    if (carry != 0) {
        a = "1" + a;
    }
    return a;
}

int main() {
    int cnt = 0;
    bool flag = true;
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    while (a != b) {
        cout << a << " + " << b << " = ";
        a = add(a, b);
        cout << a << endl;
        b = a;
        reverse(b.begin(), b.end());
        cnt++;
        if (cnt == 10) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << a <<" is a palindromic number.";
    } else {
        cout << "Not found in 10 iterations.";
    }
    return 0;
}