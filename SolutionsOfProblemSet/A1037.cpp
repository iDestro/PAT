#include <iostream>
#include <algorithm>
using namespace std;
bool Cmp(int a, int b) {
    return a > b;
}
int main() {
    int N, K;
    cin >> K;
    int coupon[K];
    for (int i = 0; i < K; i++) {
        cin >> coupon[i];
    }
    cin >> N;
    int item[N];
    for (int i = 0; i < N; i++) {
        cin >> item[i];
    }
    bool is_sell[N];
    for (int i = 0; i < N; i++) {
        is_sell[i] = false;
    }
    sort(coupon, coupon+K, Cmp);
    sort(item, item+N, Cmp);
    int payback = 0;
    for (int i = 0; i < K; i++) {
        if (coupon[i] > 0 && is_sell[i] == false && item[i] > 0) {
            payback += coupon[i]*item[i];
            is_sell[i] = true;
        } else {
            break;
        }
    }
    for (int i = 0; i < K; i++) {
        if (coupon[K-1-i] < 0 && is_sell[N-i-1] == false && item[N-i-1] < 0) {
            payback += coupon[K-1-i]*item[N-i-1];
            is_sell[N-i-1] = true;
        } else {
            break;
        }
    }
    cout << payback;
    return 0;
}