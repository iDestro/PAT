#include <iostream>
#define maxn 10000001
using namespace std;
int prime[maxn];
int pNum = 0;
bool p[maxn] = {false};
void find_prime(int n) {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            if (pNum >= n) break;
            for (int j = i+i; j < maxn; j+=i) {
                p[j] = true;
            }
        }
    }
}
int main() {
    int M, N, count = 0;
    cin >> M >> N;
    find_prime(N);
    for (int i = M-1; i < N; i++) {
        cout << prime[i];
        count++;
        if (count % 10 != 0 && i < N-1) {
            cout << " ";
        } else {
            cout << endl;
         }
    }
    return 0;
}