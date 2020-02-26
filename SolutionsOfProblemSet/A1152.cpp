/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-17 22:35:22
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-18 23:20:34
 */
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

bool isprime(long x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int l, k;
    bool flag = false;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i <= l-k; i++) {
        string subs = s.substr(i, k);
        long t = stoi(subs);
        if (isprime(t)) {
            cout << subs;
            flag = true;
            return 0;
        }
    }
    cout << "404";
    return 0;
}