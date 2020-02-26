#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1005;

vector<int> Adj[N];
bool vis[N];

int father[N];

void init() {
    for (int i = 0; i < N; i++) {
        father[i] = i;
    }
}

int FIND(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void UNION(int a, int b) {
    int Fa = FIND(a);
    int Fb = FIND(b);
    if (Fa != Fb) {
        father[Fa] = Fb;
    }
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    for (int i = 0; i < k; i++) {
        init();
        fill(vis, vis+N, false);
        int temp, cnt = 0;
        cin >> temp;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < Adj[j].size(); k++) {
                if (j == temp || Adj[j][k] == temp) {
                    continue;
                } else {
                    UNION(j, Adj[j][k]);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (j == temp) {
                continue;
            }
            int f = FIND(j);
            if (!vis[f]) {
                cnt++;
                vis[f] = true;
            }
        }
        cout << cnt-1 << endl;
    }
    return 0;
}