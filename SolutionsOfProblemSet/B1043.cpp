#include <iostream>
#include <string>
using namespace std;
int trans(char ch) {
    switch(ch) {
        case 'P':
            return 0;
        case 'A':
            return 1;
        case 'T':
            return 2;
        case 'e':
            return 3;
        case 's':
            return 4;
        case 't':
            return 5;
    }
    return -1;
}
int main() {
    string str;
    string s = "PATest";
    getline(cin, str);
    int hashtable[6] = {0}, sum = 0;
    for (int i = 0; i < str.length(); i++) {
        int index = trans(str[i]);
        if (index != -1) {
            hashtable[index]++;
            sum++;
        }
    }
    while (sum) {
        for (int i = 0; i < 6; i++) {
            if (hashtable[i] > 0) {
                printf("%c", s[i]);
                hashtable[i]--;
                sum--;
            }
        }
    }
    return 0;
}