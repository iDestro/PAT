#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 505
#define INF 1000000000
using namespace std;
int N, M, S, D;

typedef struct node{
    int cost;
    int len;
    node() {
        this -> cost = INF;
        this -> len = INF;
    }
}Node;

Node G[maxn][maxn];
int dis[maxn], optValue = INF;
bool vis[maxn] = {false};

vector<int> pre[maxn], tempPath, path;
int Dijkstra(int s) {
    fill(dis, dis+N, INF);
    dis[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1)  {
            return -1;
        }
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v].len != INF) {
                if (dis[u] + G[u][v].len < dis[v]) {
                    dis[v] = dis[u] + G[u][v].len;
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v].len == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    return 1;
}

void DFS(int v) {
    if (v == S) {
        tempPath.push_back(v);
        int value = 0;
        for (int i = tempPath.size()-1; i > 0; i--) {
            int s = tempPath[i], e = tempPath[i-1];
            value += G[s][e].cost;
        }
        if (value < optValue) {
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cin >> G[u][v].len;
        cin >> G[u][v].cost;
        G[v][u].len = G[u][v].len;
        G[v][u].cost = G[u][v].cost;
    }
    Dijkstra(S);
    DFS(D);
    int tot = 0;
    for (int i = path.size()-1; i >= 0; i--) {
        int s = path[i], e = path[i-1];
        cout << s << " ";
        if (i != 0) {
            tot += G[s][e].len;
        }
    }
    cout << tot << " ";
    cout << optValue;
}