/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-16 23:38:36
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-16 23:51:18
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
vector<int> adj[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m, u, v, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        fill(vis, vis+maxn, true);
        cin >> num;
        vector<int> temp(num);
        for (int j = 0; j < num; j++) {
            cin >> temp[j];
            vis[temp[j]] = false;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (!vis[temp[i]]) {
                dfs(temp[i]);
                cnt++;
            }
        }
        if (cnt == temp.size()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}