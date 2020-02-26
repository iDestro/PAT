#include <cstdio>
using namespace std;
int main() {
    int T;
    long long A, B, C;
    scanf("%d", &T);
    bool res[T];
    for (int i = 0; i < T; i++) {
        scanf("%lld %lld %lld", &A, &B, &C);
        long long D = A + B;
        if (A > 0 && B > 0 && D < 0) res[i] = true;
        else if (A < 0 && B < 0 && D >= 0) res[i] = false;
        else if (D > C) res[i] = true;
        else res[i] = false;
    }
    for (int i = 0; i < T; i++) {
        printf("Case #%d: %s\n", i+1, (res[i] ? "true" : "false"));
    }
    return 0;
}