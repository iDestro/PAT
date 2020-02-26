/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-16 23:57:40
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-17 20:41:27
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
#include <set>
#define maxn 205
#define INF 1000000000
using namespace std;
int G[maxn][maxn];
bool vis[maxn];
int main() {
    fill(G[0], G[0]+maxn*maxn, 0);
    int n, m, k, u, v, d, num, pre, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        G[u][v] = G[v][u] = d;
    }
    cin >> k;
    vector<string> ans;
    int min_idx = -1, min = INF;
    for (int i = 1; i <= k; i++) {
        cin >> num;
        int len = 0;
        fill(vis, vis+maxn, false);
        bool isSimple = true, over = false, visAll = true;
        vector<int> dot(num);
        for (int j = 0; j < num; j++) {
            cin >> dot[j];
            if (!vis[dot[j]]) {
                vis[dot[j]] = true;
            } else if (j != num-1){
                isSimple = false;
            }
        }
        for (int j = 1; j < num; j++) {
            if (G[dot[j-1]][dot[j]] != 0) {
                len += G[dot[j-1]][dot[j]];
            } else {
                ans.push_back("Path "+to_string(i)+": NA (Not a TS cycle)");
                over = true;
                break;
            }
        }
        if (over) continue;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                visAll = false;
                break;
            }
        }
        if (dot[0] == dot[num-1] && visAll) {
            if (len < min) {
                min = len;
                min_idx = i;
            }
            if (isSimple) {
                ans.push_back("Path "+to_string(i)+": "+to_string(len)+" (TS simple cycle)");
            } else {
                ans.push_back("Path "+to_string(i)+": "+to_string(len)+" (TS cycle)");
            }
        } else {
            ans.push_back("Path "+to_string(i)+": "+to_string(len)+" (Not a TS cycle)");
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    if (min_idx != -1) {
        printf("Shortest Dist(%d) = %d", min_idx, min);
    }
}