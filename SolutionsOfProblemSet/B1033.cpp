#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s1, s2;
    int hashmap[256] = {0};
    getline(cin, s1);
    for (int i = 0; i < s1.length(); i++) {
        hashmap[s1[i]] = 1;
    }
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++) {
        if (isupper(s2[i]) && hashmap['+'] == 1) {
            continue;
        }
        if (hashmap[toupper(s2[i])] != 1) {
            printf("%c", s2[i]);
        }
    }
    cout << endl;
    return 0;
}