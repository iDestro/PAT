#include <iostream>
#include <vector>
#include <algorithm>

#define maxn 510
#define INF 1000000000
using namespace std;

vector<int> prel[maxn], pret[maxn];
vector<int> pathl, patht, tempPathl, tempPatht;

typedef struct node {
    int l, t;
    node() {
        this -> l = INF;
        this -> t = INF;
    }
}Node;

Node G[maxn][maxn];
int dis[maxn], tc[maxn];
bool vis[maxn];
int N, M, S, D;

void DijkstraL(int s) {
    fill(vis, vis+N, false);
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
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v].l != INF) {
                if (dis[u] + G[u][v].l < dis[v]) {
                    dis[v] = dis[u] + G[u][v].l;
                    prel[v].clear();
                    prel[v].push_back(u);
                } else if (dis[u] + G[u][v].l == dis[v]) {
                    prel[v].push_back(u);
                }
            }
        }
    }
}

void DijkstraT(int s) {
    fill(vis, vis+N, false);
    fill(tc, tc+N, INF);
    tc[s] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && tc[j] < min) {
                min = tc[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v].t != INF) {
                if (tc[u] + G[u][v].t < tc[v]) {
                    tc[v] = tc[u] + G[u][v].t;
                    pret[v].clear();
                    pret[v].push_back(u);
                } else if (tc[u] + G[u][v].t == tc[v]) {
                    pret[v].push_back(u);
                }
            }
        }
    }
}
int optTime = INF;
void DFSL(int u) {
    if (u == S) {
        tempPathl.push_back(u);
        int time = 0;
        for (int i = tempPathl.size()-1; i > 0; i--) {
            int id = tempPathl[i], id_next = tempPathl[i-1];
            time += G[id][id_next].t;
        }
        if (time < optTime) {
            optTime = time;
            pathl = tempPathl;
        }
        tempPathl.pop_back();
        return;
    }
    tempPathl.push_back(u);
    for (int i = 0; i < prel[u].size(); i++) {
        DFSL(prel[u][i]);
    }
    tempPathl.pop_back();
}

int optDis = INF;


void DFST(int u) {
    if (u == S) {
        tempPatht.push_back(u);
        if (tempPatht.size() < optDis) {
            optDis = tempPatht.size();
            patht = tempPatht;
        }
        tempPatht.pop_back();
        return;
    }
    tempPatht.push_back(u);
    for (int i = 0; i < pret[u].size(); i++) {
        DFST(pret[u][i]);
    }
    tempPatht.pop_back();
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, s, l, t;
        cin >> u >> v >> s >> l >> t;
        G[u][v].l = l;
        G[u][v].t = t;
        if (s == 0) {
            G[v][u].l = l;
            G[v][u].t = t;
        }
    }
    cin >> S >> D;
    DijkstraL(S);
    DijkstraT(S);
    DFSL(D);
    DFST(D);
    if (patht == pathl) {
        cout << "Distance = " << dis[D] << "; Time = " << tc[D] << ": ";
        for (int i = pathl.size()-1; i >= 0; i--) {
            cout << pathl[i];
            if (i != 0) {
                cout << " -> ";
            }
        }
    } else {
        cout << "Distance = " << dis[D] << ": ";
        for (int i = pathl.size()-1; i >= 0; i--) {
            cout << pathl[i];
            if (i != 0) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Time = " << tc[D] << ": ";
        for (int i = patht.size()-1; i >= 0; i--) {
            cout << patht[i];
            if (i != 0) {
                cout << " -> ";
            }
        }
    }
}