#include <iostream>
using namespace std;

int main() {
    int N, row = 0;
    char ch;
    cin >> N >> ch;
    for (int i = 0; i < N; i++) {
        if ((4+2*i)*i+1 > N) {
            row = i-1;
            break;
        }
    }
    for (int i = row; i >= 1; i--) {
        for (int j = 0; j < row-i; j++) cout << " ";
        for (int k = 0; k < 2*i+1; k++) cout << ch;
        cout << endl;
    }
    for (int i = 0; i < row; i++) cout << " ";
    cout << ch << endl;
    for (int i = 1; i <= row; i++) {
        for (int j = 0; j < row-i; j++) cout << " ";
        for (int k = 0; k < 2*i+1; k++) cout << ch;
        cout << endl;
    }
    cout << N-(row*(3+2*row+1)+1);
    return 0;
}