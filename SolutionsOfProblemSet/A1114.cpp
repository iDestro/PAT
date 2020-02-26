#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> Adj[10000];
int estate[10000], area[10000];
bool vis[10000];
bool isvalid[10000];

typedef struct Node{
    int id;
    int M;
    double e, a;
    Node(int _id, int _M, double _e, double _a) {
        this -> id = _id;
        this -> M = _M;
        this -> e = _e;
        this -> a = _a;
    }
}P;

vector<P> ans;

void DFS(int s, int &tot_e, int &tot_a, int &num, int &M) {
    vis[s] = true;
    M++;
    tot_e += estate[s];
    tot_a += area[s]; 
    if (s < num) {
        num = s;
    }
    for (int i = 0; i < Adj[s].size(); i++) {
        int v = Adj[s][i];
        if (!vis[v] && isvalid[v]) {
            DFS(v, tot_e, tot_a, num, M);
        }
    }
}

bool cmp(P A, P B) {
    if (A.a != B.a) {
        return A.a > B.a;
    } else {
        return A.id < B.id;
    }
}

int main() {
    fill(vis, vis+10000, false);
    fill(isvalid, isvalid+10000, false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, f, m, k, e, v, a;
        cin >> u >> m >> f >> k;
        isvalid[u] = true;
        if (m != -1) {
            Adj[u].push_back(m);
            Adj[m].push_back(u);
            isvalid[m] = true;
        }
        if (f != -1) {
            Adj[u].push_back(f);
            Adj[f].push_back(u);
            isvalid[f] = true;
        }
        for (int j = 0; j < k; j++) {
            cin >> v;
            Adj[u].push_back(v);
            Adj[v].push_back(u);
            isvalid[v] = true;
        }
        cin >> e >> a;
        estate[u] = e;
        area[u] = a;
    }
    int cnt = 0;
    for (int i = 0; i < 10000; i++) {
        if (!vis[i] && isvalid[i]) {
            int num = 10000, tot_e = 0, tot_a = 0, M = 0;
            DFS(i, tot_e, tot_a, num, M);
            ans.push_back(P(num, M, (double)tot_e/M, (double)tot_a/M));
            
            cnt++;
        }
    }
    cout << cnt << endl;
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].M, ans[i].e, ans[i].a);
    }
    return 0;
}