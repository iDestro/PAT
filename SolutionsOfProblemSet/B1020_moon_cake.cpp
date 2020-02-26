#include <iostream>
#include <algorithm>
using namespace std;
typedef struct MC{
    double total_price;
    double quality;
    double avg_price;
}MoonCake;

bool Cmp(MoonCake A, MoonCake B) {
    return A.avg_price > B.avg_price;
}

int main() {
    int K, M;
    double max = 0;
    cin >> K >> M;
    MoonCake MC[K];
    for (int i = 0; i < K; i++) {
        cin >> MC[i].quality;
    }
    for (int i = 0; i < K; i++) {
        cin >> MC[i].total_price;
        MC[i].avg_price = MC[i].total_price / MC[i].quality;
    }
    sort(MC, MC+K, Cmp);
    for (int i = 0; i < K && M > 0; i++) {
        if (MC[i].quality <= M) {
            max += MC[i].total_price;
            M -= MC[i].quality;
        } else {
            max += M*MC[i].avg_price;
            break;
        }
    }
    printf("%.2lf", max);
    return 0;
}