/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 00:00:35
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 00:35:57
 */
 
#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
#include <map>
using namespace std;
map<string, int> cnt;
int main() {
    string str, res = "";
    int s, e;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) || isdigit(str[i])) {
            if (i == str.length() - 1) {
                res += tolower(str[i]);
                cnt[res]++;
                res = "";
            } else {
                res += tolower(str[i]);
            }
        } else if (res.length() > 0) {
            cnt[res]++;
            res = "";
        }
    }
    map<string, int> :: iterator iter;
    int max = -1;
    string maxWord;
    iter = cnt.begin();
    while (iter != cnt.end()) {
        if (iter -> second > max) {
            max = iter -> second;
            maxWord = iter -> first;
        } else if (iter -> second == max && iter -> first < maxWord) {
            maxWord = iter -> first;
        }
        iter++;
    }
    cout << maxWord << " " << cnt[maxWord];
}
 