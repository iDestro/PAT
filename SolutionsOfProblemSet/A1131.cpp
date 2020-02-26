/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-09 23:02:16
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-11 00:27:16
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 1000000000
#include <cstdio>
#define maxn 10000
using namespace std;

vector<int> adj[maxn], path, tempPath;
unordered_map<int, int> line;
bool vis[maxn];

int transferCnt(vector<int> a) {
    int cnt = -1, preline = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preline) cnt++;
        preline = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}

int S, D, mincnt, minTransfer;

void dfs(int u, int cnt) {
    if (u == D && (cnt < mincnt ||(cnt == mincnt && transferCnt(tempPath) < minTransfer))) {
        mincnt = cnt;
        path = tempPath;
        minTransfer = transferCnt(tempPath);
    }
    if (u == D) {
        return;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            vis[v] = true;
            tempPath.push_back(v);
            dfs(v, cnt+1);
            tempPath.pop_back();
            vis[v] = false;
        }
    }
}

int main() {
    int N, M, pre, temp, K;
    fill(vis, vis+maxn, false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M >> pre;
        for (int j = 1; j < M; j++) {
            cin >> temp;
            adj[temp].push_back(pre);
            adj[pre].push_back(temp);
            line[temp*10000+pre] = line[pre*10000+temp] = i+1;
            pre = temp;
        }
    }
    cin >> K;
    while (K--) {
        cin >> S >> D;
        tempPath.clear();
        path.clear();
        tempPath.push_back(S);
        vis[S] = true;
        mincnt = minTransfer = INF;
        dfs(S, 0);
        vis[S] = false;
        int preline = 0, preTransfer = S;
        cout << mincnt << endl;
        for (int i = 1; i < path.size(); i++) {
            int cur_line = line[path[i-1]*10000+path[i]];
            if (cur_line != preline) {
                if (preline != 0) {
                    printf("Take Line#%d from %04d to %04d.\n", preline, preTransfer, path[i-1]);
                }
                preline = cur_line;
                preTransfer = path[i-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, preTransfer, D);
    }
}
