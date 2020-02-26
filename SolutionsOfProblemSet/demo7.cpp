#include <iostream>
typedef long long LL;
LL binaryPow_recursive(LL a, LL b, LL m) {
    if (b == 0) return 1;
    if (b % 2 == 1) return a * binaryPow_recursive(a, b-1, m) % m;
    else {
        LL mul = binaryPow_recursive(a, b/2, m);
        return mul*mul % m;
    }
}

LL binaryPow_iteration(LL a, LL b, LL m) {
    LL ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    return 0;
}