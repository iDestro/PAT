#include <iostream>
#include <algorithm>
#define maxn 1000010
using namespace std;
int n, p, a[maxn];

int binary_search(int i, long long x) {
    // if (a[n-1] <= x) return n;
    int l = i+1, r = n-1, mid;
    while (l < r) {
        mid = (l+r)/2;
        if (a[mid] <= x) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = binary_search(i, (long long)a[i]*p);
        ans = max(ans, j-i);
    }
    cout << ans;
    return 0;
}