#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
bool sureNoBroken[256];
bool m[256];
set<int> printed;

int main() {
    string s;
    int k, cnt = 1;
    cin >> k >> s;
    char pre = '#';
    s = s + '#';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if (i != s.length() - 1) {
            m[s[i]] = cnt % k == 0;
        }
        pre = s[i];
    }
    for (int i = 0; i < s.length()-1; i++) {
        if (sureNoBroken[s[i]]) {
            m[s[i]] = false;
        }
    }
    for (int i = 0; i < s.length()-1; i++) {
        if (m[s[i]] && printed.find(s[i]) == printed.end()) {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < s.length()-1; i++) {
        printf("%c", s[i]);
        if (m[s[i]]) {
            i = i+k-1;
        }
    }
    return 0;
}