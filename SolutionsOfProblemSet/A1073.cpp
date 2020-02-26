#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    vector<int> decimal;
    cin >> s;
    char tail_sign = s[0], exp_sign;
    int i = 3, j = 0, exp = 0, Z;
    Z = s[1];
    while (s[i] != 'E') {
        decimal.push_back(s[i]);
        i++;
    }
    exp_sign = s[++i];
    for (i = i+1; i < s.length(); i++) {
        exp = exp*10 + s[i]-'0';
    }
    if (tail_sign == '-') {
            cout << tail_sign;
    }
    if (exp_sign == '-') {
        cout << "0.";
        for (int i = 0; i < exp-1; i++) {
            cout << "0";
        }
        cout << Z-'0';
        for (int i = 0; i < decimal.size(); i++) {
            cout << decimal[i]-'0';
        }
    } else if (exp_sign == '+') {
        cout << Z - '0';
        if (exp >= decimal.size()) {
            for (int i = 0; i < decimal.size(); i++) {
                cout << decimal[i] - '0';
            }
            for (int i = decimal.size(); i < exp; i++) {
                cout << 0;
            }
        } else {
            for (int i = 0; i < exp; i++) {
                cout << decimal[i] - '0';
            }
            cout << ".";
            for (int i = exp; i < decimal.size(); i++) {
                cout << decimal[i] - '0';
            }
        }
    }
    return 0;
}