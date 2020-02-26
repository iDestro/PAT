#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int hashtable[128] = {0};
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            hashtable[tolower(str[i])]++;
        }
    }
    int max_idx = 0;
    for (int i = 1; i < 128; i++) {
        if (hashtable[i] > hashtable[max_idx]) {
            max_idx = i;
        }
    }
    printf("%c %d", max_idx, hashtable[max_idx]);
}