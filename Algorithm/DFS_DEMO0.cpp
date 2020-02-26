/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-19 18:40:09
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 09:22:36
 */

#include <iostream>
#define maxn 30
using namespace std;

int w[maxn], c[maxn], max_value = 0, V, N;

void dfs(int index, int sumW, int sumC) {
    if (index == N) {
        if (sumW <= V && sumC > max_value) {
            max_value = sumC;
        }
        return;
    }
    dfs(index+1, sumW, sumC);
    if (sumW + w[index] <= V) { // 剪纸
        dfs(index+1, sumW+w[index], sumC+c[index]);
    }
}

int main() {
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    dfs(0, 0, 0);
    cout << max_value;
    return 0;
}