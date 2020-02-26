#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string c = to_string(a+b);
    int len = c.length();
    for (int i = 0; i < len; i++) {
        cout << c[i];
        if (c[i] == '-') continue;
        if (len%3 == (i+1)%3 && i != len-1) cout << ",";
    }
    return 0;
}