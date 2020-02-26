#include <iostream>
#include <algorithm>
#include <map>
#define maxn 505
using namespace std;
int G[maxn][maxn];
bool vis[maxn];
int cnt[maxn];
int N, M, c = 0;

void dfs(int s) {
    vis[s] = true;
    c++;
    for (int i = 1; i < maxn; i++) {
        if (G[s][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    fill(G[0], G[0]+maxn*maxn, 0);
    fill(vis, vis+maxn, false);
    fill(cnt, cnt+maxn, 0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        cnt[u]++;
        cnt[v]++;
    }
    for (int i = 1; i <= N; i++) {
        cout << cnt[i];
        if (i != N) {
            cout << " ";
        }
    }
    cout << endl;
    int odd_cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] % 2 != 0) {
            odd_cnt++;
        }
    }
    dfs(1);
    if (odd_cnt == 0 && c == N) {
        cout << "Eulerian";
    } else if (odd_cnt == 2 && c == N) {
        cout << "Semi-Eulerian";
    } else {
        cout << "Non-Eulerian";
    }
    return 0;
}