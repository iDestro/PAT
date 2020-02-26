#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string num;
    int exp;
}F;

void trans(F &f, int N) {
    int count = 0;
    int i = 0;
    while (f.num.length() > 0 && f.num[0] == '0') {
        f.num.erase(f.num.begin());
    }
    if (f.num[0] == '.') {
        f.num.erase(f.num.begin());
        while (f.num[0] == '0') {
            f.num.erase(f.num.begin());
            count--;
        }
    } else {
        for (; i < f.num.length() && f.num[i] != '.'; i++) {
            count++;
        }
        if (i != f.num.length()) {
            f.num.erase(f.num.begin() + i);
        }
    }
    if (f.num.length() == 0) {
        f.exp = 0;
    } else {
        f.exp = count;
    }
    string res;
    for (i = 0; i < N; i++) {
        if (i < f.num.length()) {
            res += f.num[i];
        } else {
            res += "0";
        }
    }
    f.num = res;
}

int main() {
    int N;
    F A, B;
    cin >> N >> A.num >> B.num;
    trans(A, N);
    trans(B, N);
    if (A.num == B.num && A.exp == B.exp) {
        cout << "YES ";
        cout << "0." << A.num << "*10^" << A.exp;
    } else {
        cout << "NO ";
        cout << "0." << A.num << "*10^" << A.exp << " ";
        cout << "0." << B.num << "*10^" << B.exp;
    }
    return 0;
}