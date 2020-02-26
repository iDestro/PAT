#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1,i-1);
    int n = stoi(s.substr(i+1));
    if (s[0] == '-') cout << '-';
    if (n < 0) {
        cout << "0.";
        for (i = 0; i < -n-1; i++) {
            cout << "0";
        }
        cout << t[0];
        for (i = 2; i < t.length(); i++) {
            cout << t[i];
        }
    } else {
        cout << s[1];
        for (i = 2; i < t.length() && cnt < n; i++, cnt++) {
            cout << t[i];
        }
        if (i == t.length()) {
            for (int i = 0; i < n - cnt; i++) {
                cout << "0";
            }
        } else {
            cout << ".";
            for (; i < t.length(); i++) {
                cout << t[i];
            }
        }
    }
    return 0;
}