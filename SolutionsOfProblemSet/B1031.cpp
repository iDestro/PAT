#include <iostream>
#include <string>
using namespace std;
int main() {
    int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char idx[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int z, N;
    cin >> N;
    string str;
    bool flag1 = true;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        cin >> str;
        bool flag2 = true;
        for (int i = 0; i < str.length()-1; i++) {
            if (str[i] < '0' || str[i] > '9') {
                cout << str << endl;
                flag1 = false;
                flag2 = false;
                break;
            }
        }
        if (!flag2) {
            continue;
        }
        for (int i = 0; i < str.length()-1; i++) {
            sum += (str[i]-'0')*w[i];
        }
        z = sum % 11;
        if (str[str.length()-1] != idx[z]) {
            flag1 = false;
            cout << str << endl;
        }
    }
    if (flag1) {
        cout << "All passed";
    }
    return 0;
}