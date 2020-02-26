#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    string name, pwd;
    cin >> N;
    vector<string> arr;
    for (int i = 0; i < N; i++) {
        cin >> name >> pwd;
        bool flag = false;
        for (int j = 0; j < pwd.length(); j++) {
            if (pwd[j] == '1') {
                flag = true;
                pwd[j] = '@';
            } else if (pwd[j] == '0') {
                flag = true;
                pwd[j] = '%';
            } else if (pwd[j] == 'l') {
                flag = true;
                pwd[j] = 'L';
            } else if (pwd[j] == 'O') {
                flag = true;
                pwd[j] = 'o';
            }
        }
        if (flag) {
            arr.push_back(name+" "+pwd);
        }
    }
    if (arr.size() != 0) {
        cout << arr.size() << endl;
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << endl;
        }
    } else if (N == 1) {
        cout << "There is 1 account and no account is modified";
    } else {
        cout << "There are "<< N <<" accounts and no account is modified";
    }
    return 0;
}