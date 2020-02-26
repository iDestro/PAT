/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-16 23:08:04
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-16 23:31:03
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int id, n;
    cin >> n;
    vector<int> cnt(n+1), a(n+1);
    fill(cnt.begin(), cnt.begin(), 0);
    for (int i = 1; i <= n; i++) {
        cin >>id;
        if (id < 0) {
            cnt[i]--;
        } else {
            cnt[i]++;
        }
        a[i] = id;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}