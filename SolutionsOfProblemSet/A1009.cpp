#include <cstdio>

struct Poly {
    int exp;
    double cof;
}p[1001];

double ans[2001] = {0};

int main() {
    int n1, n2, exp, cnt = 0;
    double cof;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d%lf", &p[i].exp, &p[i].cof);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d%lf", &exp, &cof);
        for (int i = 0; i < n1; i++) {
            ans[p[i].exp+exp] += p[i].cof*cof;
        }
    }
    for (int i = 0; i < 2001; i++) {
        if (ans[i] != 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--) {
        if (ans[i] != 0) {
            printf(" %d %.1lf", i, ans[i]);
        }
    }
    return 0;
}