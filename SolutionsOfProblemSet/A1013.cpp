#include <iostream>
#define maxn 1005
#define INF 1000000000
#include <algorithm>
using namespace std;
int G[maxn][maxn], tempG[maxn][maxn];
bool vis[maxn];

int N, M, K;

void DFS(int u) {
    vis[u] = true;
    for (int i = 1; i <= N; i++) {
        if (!vis[i] && G[u][i] != INF) {
            DFS(i);
        }
    }
}


int main() {
    fill(G[0], G[0]+maxn*maxn, INF);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    for (int i = 0; i < K; i++) {
        fill(vis, vis+maxn, false);
        int temp;
        cin >> temp;
        vis[temp] = true;
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (!vis[j]) {
                DFS(j);
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }
    return 0;
}