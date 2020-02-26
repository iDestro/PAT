#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string A, B;
    string idx = "0123456789JQK";
    cin >> A >> B;
    int i = A.length()-1, j = B.length()-1, cnt = 1;
    if (i > j) {
        for (int k = 0; k < i-j; k++) {
            B = '0' + B;
        }
    } else {
        for (int k = 0; k < i-j; k++) {
            A = '0' + A;
        }
    }
    i = A.length()-1, j = B.length()-1, cnt = 1;
    while ( i >= 0 && j >= 0) {
        if (cnt % 2 == 0) {
            int res = B[j]-A[i];
            if (res < 0) {
                res += 10;
            }
            B[j] = idx[res];
        } else {
            int res = (A[i] + B[j] - 2*'0') % 13;
            B[j] = idx[res];
        }
        i--, j--, cnt++;
    }
    cout << B;
    return 0;
}