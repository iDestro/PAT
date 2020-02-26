/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-16 00:05:22
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-16 00:38:09
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 1005
using namespace std;
int G[maxn][maxn];
vector<int> in(maxn), temp_in(maxn), ans;
int main() {
    int n, m, u, v, k, t;
    cin >> n >> m;
    fill(G[0], G[0]+maxn*maxn, 0);
    fill(in.begin(), in.end(), 0);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u][v] = 1;
        in[v]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        temp_in = in;
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (temp_in[t] > 0) {
                ans.push_back(i);
                while (++j < n) {
                    cin >> t;
                }
                break;
            } else {
                for (int v = 1; v <= n; v++) {
                    if (G[t][v] == 1) {
                        temp_in[v]--;
                    }
                }
            }
        }
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}