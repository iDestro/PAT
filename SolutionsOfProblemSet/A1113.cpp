#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N/2; i++) {
        sum1 += a[i];
        sum2 += a[N-i-1];
    }
    if (N % 2 != 0) {
        sum2 += a[N/2];
        cout << "1 ";
    } else {
        cout << "0 ";
    }
    cout << abs(sum1-sum2);
    return 0;
}