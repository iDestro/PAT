/*
 * @Descripttion: 1100 Mars Numbers (20 分)
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-23 23:50:42
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-24 09:26:38
 */


#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
string Mars[25] =  {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", 
                 "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<string, int> mp;

void init() {
    for (int i = 0; i <= 12; i++) {
        mp[Mars[i]] = i;
    }
    for (int i = 13; i <= 24; i++) {
        mp[Mars[i]] = (i-12)*13;
    }
}

int main() {
    init();
    int N;
    string s;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if (isdigit(s[0])) {
            int num = stoi(s);
            if (num > 12) {
                cout << Mars[num/13+12];
                if (num % 13 != 0) {
                    cout << " " << Mars[num%13];
                }
                cout << endl;
            } else {
                cout << Mars[num] << endl;
            }
        } else {
            string temp = "";
            int res = 0;
            for (int i = 0; i < s.length(); i++) {
                if (i == s.length()-1) {
                    temp += s[i];
                    res += mp[temp];
                } else if (s[i] != ' '){
                    temp += s[i];
                } else {
                    res += mp[temp];
                    temp = "";
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}