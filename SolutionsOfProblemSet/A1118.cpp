#include <iostream>
#include <algorithm>
#define maxn 10005
using namespace std;

int father[maxn];
bool vis[maxn];

void init() {
    for (int i = 0;i <= maxn; i++) {
        father[i] = i;
    }
    fill(vis, vis+maxn, false);
}

int Find(int x) {
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

void Union(int a, int b) {
    int Fa = Find(a);
    int Fb = Find(b);
    if (Fa != Fb) {
        father[Fa] = Fb;
    }
}



int main() {
    init();
    int N, K, fb, tb, max = -1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        cin >> fb;
        if (fb > max) max = fb;
        for (int j = 1; j < K; j++) {
            cin >> tb;
            if (tb > max) max = tb;
            Union(fb, tb);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= max; i++) {
        int f = Find(i);
        if (!vis[f]) {
            cnt++;
            vis[f] = true;
        }
    }
    cout << cnt << " " << max << endl;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int fa, fb;
        cin >> fa >> fb;
        fa = Find(fa);
        fb = Find(fb);
        if (fa != fb) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}