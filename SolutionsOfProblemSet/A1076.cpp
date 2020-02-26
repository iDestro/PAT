/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-30 10:11:29
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-30 11:05:51
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, L, K;
int G[1005][1005] = {0}, inq[1005] = {false};

void bfs(int root, int &nums) {
    queue<int> Q;
    int level = 1;
    Q.push(root);
    inq[root] = true;
    int lastNode = root;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++) {
            if (G[u][i] != 0 && !inq[i]) {
                Q.push(i);
                nums++;
                inq[i] = true;
            }
        }
        if (u == lastNode) {
            level++;
            lastNode = Q.back();
            if (level > L) {
                break;
            }
        }
    }
}

int main() {
    int n, u;
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> u;
            G[u][i] = 1;
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        fill(inq, inq+1005, false);
        cin >> u;
        int nums = 0;
        bfs(u, nums);
        cout << nums << endl;
    }
    return 0;
}