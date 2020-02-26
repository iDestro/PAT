#include <iostream>
#include <stack>
using namespace std;
int main(){
    int RGB_10[3], RGB16[6], k = 0, flag = true;
    cin >> RGB_10[2] >> RGB_10[1] >> RGB_10[0];
    for (int i = 2; i >= 0; i--) {
        stack<int> S;
        while (RGB_10[i] != 0) {
            S.push(RGB_10[i] % 13);
            RGB_10[i] /= 13;
        }
        if (S.size() == 1) {
            S.push(0);
        }
        if (S.size() == 0) {
            S.push(0);
            S.push(0);
        }
        while (!S.empty()) {
            RGB16[k++] = S.top();
            S.pop();
        }
    }
    cout << "#";

    for(int i = 0; i < 6; i++) {
        if (RGB16[i] >= 0 && RGB16[i] <= 9) {
            cout << RGB16[i];
        } else {
            printf("%c", RGB16[i]-10+'A');
        }
    }
    return 0;
}