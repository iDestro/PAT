/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-22 11:07:43
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-22 22:41:18
 */

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y, z;
}node;

int M, N, L, T;
int cube[1300][128][60] = {0};
int inq[1300][128][60] = {false};

int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
    if (z < 0 || z >= L || x < 0 || x >= M || y < 0 || y >= N) {
        return false;
    }
    if (cube[x][y][z] == 0 || inq[x][y][z] == true) {
        return false;
    }
    return true;
}

queue<Node> Q;

int bfs(int x, int y, int z) {
    int tot = 0;
    node.x = x, node.y = y, node.z = z;
    Q.push(node);
    inq[x][y][z] = true;
    while (!Q.empty()) {
        Node front = Q.front();
        Q.pop();
        tot++;
        for (int i = 0; i < 6; i++) {
            int newX = front.x + X[i];
            int newY = front.y + Y[i];
            int newZ = front.z + Z[i];
            if (judge(newX, newY, newZ)) {
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                Q.push(node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if (tot >= T) {
        return tot;
    } else {
        return 0;
    }
}

int main() {
    int ans = 0;
    cin >> M >> N >> L >> T;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> cube[j][k][i];
            }
        }
    }
    
    for (int z = 0; z < L; z++) {
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (cube[x][y][z] != 0 && !inq[x][y][z]) {
                    ans += bfs(x, y, z);
                }
            }
        }
    }
    cout << ans;
    return 0;
}