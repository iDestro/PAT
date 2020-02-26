#include <iostream>
#include <math.h>
using namespace std;
int telly = 0;
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
void generateP(int index) {
    if (index == n+1) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (abs(i-j) == abs(P[i]-P[j])) {
                    return;
                }
            }
        }
        telly++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (hashTable[i] == false) {
            P[index] = i;
            hashTable[i] = true;
            generateP(index+1);
            hashTable[i] = false;
        }
    }
}
int main() {
    cin >> n;
    generateP(1);
    cout << telly;
    return 0;
}