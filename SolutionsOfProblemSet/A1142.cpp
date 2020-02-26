/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-14 23:37:49
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-19 00:00:55
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 205
using namespace std;
int G[maxn][maxn];
bool vis[maxn];
int nv, ne;

int main() {
    fill(G[0], G[0] + maxn*maxn, 0);
    int m, u, v, k;
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        bool flag0 = true, flag1 = true;
        fill(vis, vis+maxn, false);
        vector<int> s(k);
        for (int j = 0; j < k; j++) {
            cin >> s[j];
            vis[s[j]] = true;
        }
        for (int i = 0; i < s.size() && flag0; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i != j && G[s[i]][s[j]] == 0) {
                    printf("Not a Clique\n");
                    flag0 = false;
                    break;
                }
            }
        }
        if (!flag0) continue;
        for (int i = 1; i <= nv; i++) {
            flag1 = true;
            if (!vis[i]) {
                flag1 = false;
                for (int j = 0; j < s.size(); j++) {
                    if (G[i][s[j]] != 1) {
                        flag1 = true;
                        break;
                    }
                }
                if (!flag1) {
                    printf("Not Maximal\n");
                    break;
                }
            }
        }
        if (flag0 && flag1) {
            printf("Yes\n");
        }
    }
    return 0;
}