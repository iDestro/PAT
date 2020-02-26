#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

vector<vector<int> > Adj;
set<int> ans, temp;
int n;

bool *vis;
int *father;


int maxHeight = -1;

void dfs(int s, int height) {
    vis[s] = true;

    if (height > maxHeight) {
        maxHeight = height;
        temp.clear();
        temp.insert(s);
    } else if (height == maxHeight) {
        temp.insert(s);
    }

    for (int i = 0; i < Adj[s].size(); i++) {
        int v = Adj[s][i];
        if (!vis[v]) {
            dfs(v, height+1);
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
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
        a = father[z];
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
    scanf("%d", &n);
    Adj.resize(n+1);
    vis = new bool[n+1];
    father = new int[n+1];
    init();
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        UNION(u, v);
    }
    fill(vis, vis+n+1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int f = FIND(i);
        if (!vis[f]) {
            cnt++;
            vis[f] = true;
        }
    }

    if (cnt > 1) {
        printf("Error: %d components\n", cnt);
        return 0;
    }
    fill(vis, vis+n+1, false);
    dfs(1, 0);
    ans = temp;
    fill(vis, vis+n+1, false);
    dfs(*ans.begin(), 0);
    for (auto it = temp.begin(); it != temp.end(); it++) {
        ans.insert(*it);
    }
    for (auto it = ans.begin(); it != ans.end(); it++) {
        printf("%d\n", *it);
    }
}