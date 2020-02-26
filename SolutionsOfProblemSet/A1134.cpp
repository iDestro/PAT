/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-12 00:12:30
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-12 00:34:26
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#define maxn 10005
using namespace std;
vector<int> adj[maxn];

bool judge(unordered_map<int, bool> nodes) {
    for (int u = 0; u < maxn; u++) {
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!nodes[u] && !nodes[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m, k, u, v, num, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    while (k--) {
        unordered_map<int, bool> nodes; 
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> t;
            nodes[t] = true;
        }
        if (judge(nodes)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}