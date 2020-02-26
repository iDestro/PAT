#include <iostream>
using namespace std;
int main() {
    long long T, A, B, C;
    cin >> T;
    bool *res = new bool[T];
    for (int i = 0; i < T; i++) {
        cin >> A >> B >> C;
        if (A + B > C) {
            
            res[i] = true;
        } else {
            res[i] = false;
        }
    }
    for (int i = 0 ;i < T; i++) {
        cout << "Case #"<< i+1 <<": "<< (res[i] ? "true" : "false") << endl;
    }
    return 0;
}