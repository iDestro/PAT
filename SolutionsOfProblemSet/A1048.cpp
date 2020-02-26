#include <cstdio>
int main() {
    int coins[1005] = {0}, N, payment, value;
    scanf("%d%d", &N, &payment);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        coins[value]++;
    }
    for (int i = 1; i < payment; i++) {
        if (coins[i] && coins[payment-i]) {
            if (i == payment - i && coins[i] <= 1) {
                continue;
            }
            printf("%d %d", i, payment-i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}