#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    int cnt[10] = {0};
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        cnt[str[i]-'0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            cout << i << ":" << cnt[i] << endl; 
        }
    }
    return 0;
}