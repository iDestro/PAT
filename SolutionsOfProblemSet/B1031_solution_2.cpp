#include <iostream>
#include <string>
using namespace std;

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
bool isTrue(string s) {
    int sum = 0;
    for (int i = 0; i < 17; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        sum += (s[i]-'0')*w[i];
    }
    return s[17] == m[sum % 11];
}
int main() {
    int N, flag = 0;
    string s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (!isTrue(s)) {
            flag = 1;
            cout << s << endl;
        }
    }
    if (!flag) {
        cout << "All passed";
    }
    return 0;
}