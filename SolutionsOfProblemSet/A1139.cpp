/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-14 00:24:18
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-14 01:16:41
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define maxn 10005
using namespace std;


bool vis[maxn], gender[maxn] = {false};
vector<int> adj[maxn], temp;

struct P{
    int a, b;
    P(int _a, int _b):a(_a), b(_b){}
};
vector<P> ans;
int s, d;

void dfs(int u) {
    if (u == abs(d)) {
        temp.push_back((gender[u] ? -1*u : u));
        if (temp.size() == 4 && temp[0] * temp[1] > 0 && temp[2] * temp[3] > 0) {
            ans.push_back(P(abs(temp[1]), abs(temp[2])));
        }
        temp.pop_back();
        return;
    }
    vis[u] = true;
    temp.push_back((gender[u] ? -1*u : u));
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
    temp.pop_back();
    vis[u] = false;
}

bool cmp(P A, P B) {
    if (A.a != B.a) {
        return A.a < B.a;
    } else {
        return A.b < B.b;
    }
}

int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (u < 0) {
            gender[abs(u)] = true;
        }
        if (v < 0) {
            gender[abs(v)] = true;
        }
        adj[abs(u)].push_back(abs(v));
        adj[abs(v)].push_back(abs(u));
    }
    cin >> k;
    while (k--) {
        ans.clear();
        temp.clear();
        fill(vis, vis+maxn, false);
        cin >> s >> d;
        dfs(abs(s));
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++) {
            printf("%04d %04d\n", ans[i].a, ans[i].b);
        }
    }
}