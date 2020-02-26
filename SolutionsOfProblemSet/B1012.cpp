#include <cstdio>
int main() {
    int N, num;
    int A[5] = {0};
    A[4] = -1;
    int A_cnt[5] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num % 5 == 0) {
            if (num % 2 == 0) {
                A[0] += num;
                A_cnt[0]++;
            }
        } else if (num % 5 == 1){
            if (A_cnt[1] % 2 == 0) {
                A[1] += num;
            } else {
                A[1] -= num;
            }
            A_cnt[1]++;
        } else if (num % 5 == 2) {
            A[2]++;
            A_cnt[2]++;
        } else if (num % 5 == 3) {
            A[3] += num;
            A_cnt[3]++;
        } else if (num % 5 == 4 && num > A[4]){
            A[4] = num;
            A_cnt[4]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (A_cnt[i] != 0) {
            if (i == 3) {
                printf("%.1f", A[3]/(float)A_cnt[3]);
            } else {
                printf("%d", A[i]);
            }
        } else {
            printf("N");
        }
        if (i != 4) {
            printf(" ");
        }
    }
    return 0;
}