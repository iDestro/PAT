#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
    int G[205][205];
    fill(G[0], G[0]+205*205, 0);
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        bool flag1 = true, flag2 = true;
        int num;
        cin >> num;
        vector<int> path(num);
        set<int> node;
        for (int y = 0; y < num; y++) {
            cin >> path[y];
            node.insert(path[y]);
        }
        if (node.size() != n || num-1 != n || path[0] != path[num-1]) {
            flag1 = false;
        }
        for (int j = 0; j < num-1; j++) {
            if (G[path[j]][path[j+1]] == 0) {
                flag2 = false;
            }
        }
        if (flag1 && flag2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}