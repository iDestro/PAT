#include <cstdio>
// 空格的技巧

int main() {
    double A[1001] = {0}, cof;
    int K, exp, cnt = 0;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%lf", &exp, &cof);
        A[exp] = cof;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%lf", &exp, &cof);
        A[exp] += cof;
    }
    for (int i = 0; i < 1001; i++) {
        if (A[i] != 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (A[i] != 0) {
            printf(" %d %0.1f", i, A[i]);
        }
        
    }
    return 0;
}