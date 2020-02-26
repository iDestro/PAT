#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
    string s1, s2;
    bool hashtable[256] = {false};
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++) {
        hashtable[s2[i]] = true;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (hashtable[s1[i]] == false) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}