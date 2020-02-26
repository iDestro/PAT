#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n1 = 0, n2 = 0, n3 = 0, N = str.length(), k = 0;
    for (int i = 0; i < N; i++) {
        if (i > N+2-2*i) {
            n1 = i-1;
            break;
        }
    }
    n3 = n1;
    n2 = N-2*n1+2;
    char sym[n1][n2];
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            sym[i][j] = ' ';
        }
    }
    for (int i = 0; i < n1; i++) {
        sym[i][0] = str[k++];
    }
    for (int i = 1; i < n2; i++) {
        sym[n1-1][i] = str[k++];
    }
    for (int i = n1-2; i >= 0; i--) {
        sym[i][n2-1] = str[k++];
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << sym[i][j];
        }
        cout << endl;
    }
    return 0;
}