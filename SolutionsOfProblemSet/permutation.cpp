#include <iostream>
using namespace std;
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
void generateP(int index) {
    if (index == n+1) {
        for (int i = 1; i <= n; i++) {
            cout << P[i];
        }
        cout << endl;
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
    return 0;
}