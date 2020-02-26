#include <iostream>
#include <stack>
using namespace std;
int main() {
    int A, B, C, D;
    stack<int> S;
    cin >> A >> B >> D;
    C = A + B;
    if (C == 0) {
        cout << 0;
        return 0;
    }
    while (C != 0) {
        S.push(C % D);
        C /= D;
    }
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    return 0;
}