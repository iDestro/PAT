#include <iostream>
#include <cmath>
#define maxn 101
using namespace std;

bool isprime_demo1(int N) {
    if (N <= 1) return false;
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
// N值不大的时候采用这个可以不用调用cmath库使用函数，提高效率，一般在10^5就可以
bool isprime_demo2(int N) {
    if (N <= 1) return false;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_table(int N) {
    bool *hashTable = new bool[N+1];
    for (int i = 0; i <= N; i++) {
        hashTable[i] = false;
    }
    for (int i = 1; i <= N; i++) {
        hashTable[i] = isprime_demo2(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << i << (hashTable[i] ? "是素数" : "不是素数") << endl;
    }
}

int prime[maxn];
bool p[maxn] = {false};
int pNum = 0;
void find_prime() {
    for (int i = 2; i < maxn; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}


int main() {
    find_prime();
    for (int i = 0; i < pNum; i++) {
        cout << prime[i] << endl;
    }
    return 0;
}