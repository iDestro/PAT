/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-19 23:17:27
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-20 23:12:49
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    int a[n];
    bool m0[n], m1[n];
    vector<int> ans;
    fill(m0, m0+n, false);
    fill(m1, m1+n, false);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            m0[i] = true;
        }
    }
    int min = 1000000000;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] < min) {
            min = a[i];
            m1[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (m0[i] && m1[i]) {
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    if (ans.size() == 0) {
        printf("\n");
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
        if (i != ans.size()-1) {
            printf(" ");
        }
    }
    return 0;
}