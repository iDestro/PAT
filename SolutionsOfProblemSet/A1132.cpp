/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-11 22:47:10
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-11 23:07:02
 */
#include <iostream>
using namespace std;

int strToInt(string s) {
    unsigned long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res*10 + s[i]-'0';
    }
    return res;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        string z;
        cin >> z;
        string a = z.substr(0, z.size()/2);
        string b = z.substr(z.size()/2, z.size()-1);
        int Z = strToInt(z), A = strToInt(a), B = strToInt(b);
        if (A*B > 0 && Z % (A*B) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}