#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
    double amount;
    double total_price;
    double avg_price;
}MoonCake;

bool Cmp(MoonCake A, MoonCake B) {
    return A.avg_price > B.avg_price;
}

int main() {
    int N, D;
    cin >> N >> D;
    double profit = 0;
    MoonCake mc[N];
    for (int i = 0; i < N; i++) {
        cin >> mc[i].amount;
    }
    for (int i = 0; i < N; i++) {
        cin >> mc[i].total_price;
        mc[i].avg_price = mc[i].total_price / mc[i].amount;
    }
    sort(mc, mc+N, Cmp);
    for (int i = 0; i < N && D > 0; i++) {
        if (D > mc[i].amount) {
            D -= mc[i].amount;
            profit += mc[i].total_price;
        } else {
            profit += D*mc[i].avg_price;
            D = 0;
        }
    }
    printf("%.2f", profit);
    return 0;
}