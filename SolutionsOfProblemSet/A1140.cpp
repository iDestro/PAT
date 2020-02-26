/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-14 22:34:00
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-15 21:52:59
 */
#include <iostream>
using namespace std;
int main() {
    string s;
    int n;
    cin >> s >> n;
    if (n == 0) {
        cout << s;
        return 0;
    }
    while (--n) {
        string res = "";
        int cnt = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i+1]) {
                cnt++;
            } else {
                res += s[i] + to_string(cnt);
                cnt = 1;
            }
        }
        s = res;
    }
    cout << s;
    return 0;
}