#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 100001
using namespace std;
struct Factor {
    int x, cnt;
}fac[10];

int cnt = 0;

bool Cmp(Factor A, Factor B) {
    return A.x < B.x;
}
int prime[maxn];
bool p[maxn] = {false};
int pNum = 0;
void find_prime(int num) {
    for (int i = 2; i < num; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < num; j+=i) {
                p[j] = true;
            }
        }
    }
}
void f(int num) {
    for (int i = 0; i < pNum && prime[i] <= sqrt(num); i++) {
        if (num % prime[i] == 0) {
            fac[cnt].x = prime[i];
            fac[cnt].cnt = 0;
            while (num % prime[i] == 0) {
                fac[cnt].cnt++;
                num /= prime[i];
            }
            cnt++;
        }
        if (num == 0) {
            break;
        }
    }
    if (num != 1) {
        fac[cnt].x = num;
        fac[cnt++].cnt = 1;
    }
}
int main() {
    int num;
    cin >> num;
    if (num == 1) {
        cout << "1=1";
        return 0;
    }
    find_prime(sqrt(num)+1);
    f(num);
    sort(fac, fac+cnt, Cmp);
    cout << num << "=";
    for (int i = 0; i < cnt; i++) { 
        if (fac[i].cnt != 1) {
            cout << fac[i].x << "^" << fac[i].cnt;
        } else {
            cout << fac[i].x;
        }
        if (i != cnt-1) {
            cout << "*";
        }
    }
    return 0;
}