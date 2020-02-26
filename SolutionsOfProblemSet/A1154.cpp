/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-18 00:28:00
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-18 22:45:47
 */
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
using namespace std;
struct Node {int u, v;};
int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    Node e[m];
    int color[n];
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v;
    }
    cin >> k;
    unordered_set<int> cnt;
    for (int i = 0; i < k; i++) {
        bool flag = true;
        cnt.clear();
        for (int j = 0; j < n; j++) {
            cin >> color[j];
            cnt.insert(color[j]);
        }
        for (int j = 0; j < m; j++) {
            if (color[e[j].u] == color[e[j].v]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d-coloring\n", (int)cnt.size());
        } else {
            printf("No\n");
        }
    }
    return 0;
}