#include <cstdio>
char mp[3] = {'W', 'T', 'L'};
int main() {
    int idx;
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        double temp = 0.0;
        for (int j = 0; j < 3; j++) {
            double a;
            scanf("%lf", &a);
            if (a > temp) {
                temp = a;
                idx = j;
            }
        }
        ans *= temp;
        printf("%c ", mp[idx]);
    }
    printf("%.2lf", (ans*0.65-1)*2);
    return 0;
}