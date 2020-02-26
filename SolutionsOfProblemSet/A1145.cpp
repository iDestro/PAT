/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-15 23:20:18
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-16 23:07:16
 */
#include <iostream>
#include <cmath>
using namespace std;
int arr[10005] = {0};
bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int size, n, m, t, cnt = 0;
    cin >> size >> n >> m;
    while (!isprime(size)) size++;
    for (int i = 0 ; i < n; i++) {
        cin >> t;
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (arr[(t + i*i)%size] == 0) {
                arr[(t + i*i)%size] = t;
                flag = true;
                break;
            }
        }
        if (!flag) {
            printf("%d cannot be inserted.\n", t);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        for (int i = 0; i <= size; i++) {
            cnt++;
            int pos = (t + i*i) % size;
            if (arr[pos] == t || arr[pos] == 0) break;
        }
    }
    printf("%.1f", cnt*1.0/m);
    return 0;
}