/*
 * @Descripttion: 1018 Public Bike Management (30 分) 关系难弄
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-02 01:11:42
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-02 09:50:36
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 100000000
using namespace std;

const int maxn = 505;
int Cmax, N, Sp, M;
int G[maxn][maxn], dis[maxn], bikes[maxn];
bool vis[maxn];
vector<int> pre[maxn];

void Dijkstra(int s) {
    fill(vis, vis+N+1, false);
    fill(dis, dis+N+1, INF);
    dis[s] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1, min = INF;
        for (int j = 0; j <= N; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v <= N; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int minNeed = INF, minBack = INF;

vector<int> tempPath, path;

void DFS(int u) {
    if (u == 0) {
        // int value = 0;
        int need = 0, back = 0;
        for (int i = tempPath.size()-1; i >= 0; i--) {
            int id = tempPath[i];
            if (bikes[id] > 0) {
                back += bikes[id];
            } else {
                if (back > abs(bikes[id])) {
                    back -= abs(bikes[id]);
                } else {
                    need += abs(bikes[id]) - back;
                    back = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            path = tempPath;
        } else if (need == minNeed && back < minBack){
            minBack = back;
            path = tempPath;
        }
        return;
    }
    tempPath.push_back(u);
    for (int i = 0; i < pre[u].size(); i++) {
        DFS(pre[u][i]);
    }
    tempPath.pop_back();
}

int main() {
    cin >> Cmax >> N >> Sp >> M;
    for (int i = 1 ;i <= N; i++) {
        cin >> bikes[i];
        bikes[i] -= Cmax/2;
    }
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cin >> G[u][v];
        G[v][u] = G[u][v];
    }
    Dijkstra(0);
    DFS(Sp);
    cout << minNeed << " 0->";
    for (int i = path.size()-1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) {
            cout << "->";
        }
    }
    cout << " " << minBack;
    return 0;
}
