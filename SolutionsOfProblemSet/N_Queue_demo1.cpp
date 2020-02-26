#include <iostream>
#include <math.h>
using namespace std;
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
int telly = 0;
void generateP(int index) {
    if (index == n+1) {
        telly++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (hashTable[i] == false) {
            bool flag = true;
            for (int pre = 1; pre < index; pre++) {
                if (abs(pre-index) == abs(P[pre]-i)) {
                    flag = false;
                }
            }
            if (flag) {
                P[index] = i;
                hashTable[i] = true;
                generateP(index+1);
                hashTable[i] = false;
            }
        }
    }
}
int main() {
    cin >> n;
    generateP(1);
    cout << telly;
    return 0;
}