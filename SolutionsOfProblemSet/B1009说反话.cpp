#include <iostream>
#include <stack>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    stack<string> S;
    int len = str.length(), s = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            S.push(str.substr(s, i-s));
            s = i+1;
        } else if (i == len - 1) {
            S.push(str.substr(s, i-s+1));
        }
    }
    while (!S.empty()) {
        cout << S.top();
        S.pop();
        if (!S.empty()) {
            cout << " ";
        }
    }
    return 0;
}