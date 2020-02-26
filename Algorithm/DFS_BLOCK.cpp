/*
 * @Descripttion: 用深度优先解决块数问题
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-20 10:01:41
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 10:10:29
 */
#include <iostream>
#define maxn 100
using namespace std;
int m, n;
int matrix[maxn][maxn];
bool visted[maxn][maxn];
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (matrix[x][y] == 0 || visted[x][y] == true) return false;
    return true;
}
void dfs(int x, int y) {
    visted[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x+X[i];
        int newY = y+Y[i];
        if (judge(newX, newY)) {
            dfs(newX, newY);
        }
    }
}
int main() {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (matrix[x][y] != 0 && visted[x][y] == false) {
                ans++;
                dfs(x, y);
            }
        }
    }
    cout << ans;
    return 0;
}
