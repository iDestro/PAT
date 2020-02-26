#include <cstdio>
using namespace std;

int main() {
    char mp[5] = {'S', 'H', 'C', 'D', 'J'};
    int K, order[55], temp_order[55], new_order[55], index[55];
    scanf("%d", &K);
    for (int i = 1; i <= 54; i++) {
        scanf("%d", &order[i]);
        new_order[i] = order[i];
    }
    for (int i = 0; i < K-1; i++) {
        for (int j = 1; j <= 54; j++) {
            temp_order[j] = order[new_order[j]];
        }
        for (int j = 1; j <= 54; j++) {
            new_order[j] = temp_order[j];
        }
    }
    for (int i = 1; i <= 54; i++) {
        index[new_order[i]] = i;
    }
    for (int i = 1; i <= 54; i++) {
        printf("%c%d", mp[(index[i]-1)/13], (index[i]-1) % 13 + 1);
        if (i != 54) {
            printf(" ");
        }
    }
    return 0;
}