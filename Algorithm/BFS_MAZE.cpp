/*
 * @Descripttion: 解决迷宫问题
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-20 10:14:27
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 10:29:29
 */
#include <iostream>
#include <queue>
#define maxn 100
using namespace std;


struct node{
    int x, y, step;
}S, T, temp;

char maze[maxn][maxn];
bool inq[maxn][maxn];
int m, n;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (maze[x][y] == '*' || inq[x][y] == true) return false;
    return true;
}

int bfs() {
    queue<node> Q;
    Q.push(S);
    inq[S.x][S.y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        if (top.x == T.x && top.y == T.y) {
            return top.step + 1;
        }
        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y = Y[i];
            if (judge(newX, newY)) {
                temp.x = newX, temp.y = newY;
                temp.step = top.step + 1;
                Q.push(temp);
                inq[newX][newY] = true;
            }
        }
    }
    return -1;

}

int main() {

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    cin >> S.x >> S.y >> T.x >> T.y;
    S.step = 0;
    cout << bfs();
    return 0;
}