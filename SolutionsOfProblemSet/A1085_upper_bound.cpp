#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long n, p;
    cin >> n >> p;
    long long *a = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(a+i+1, a+n, (long long)a[i]*p) - a;
        ans = max(ans, j-i);
    }
    cout << ans;
    return 0;
}