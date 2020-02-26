/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-20 09:49:39
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 09:59:46
 */
#include <iostream>
#include <queue>
#define maxn 100
using namespace std;

struct node {
    int x, y;
}Node;

int m,n;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (matrix[x][y] == 0 || inq[x][y] == true) return false;
    return true;
}

void bfs(int x, int y){
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main() {
    int ans = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (matrix[x][y] != 0 && inq[x][y] == false) {
                ans++;
                bfs(x, y);
            }
        }
    }
    cout << ans;
}