/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 09:18:10
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-27 10:34:30
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

struct Node {
    vector<int> childs;
}nodes[100005];

int N, cnt = 0, tol_cnt = 0, max_cnt = 0;
double P, r, max;

void dfs(int root) {
    if (cnt > max_cnt) {
        max_cnt = cnt;
        tol_cnt = 1;
    } else if (cnt == max_cnt) {
        tol_cnt++;
    }
    for (int i = 0; i < nodes[root].childs.size(); i++) {
        cnt++;
        dfs(nodes[root].childs[i]);
        cnt--;
    }
}
int main() {
    int temp, root;
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1) {
            root = i;
            continue;
        }
        nodes[temp].childs.push_back(i);
    }
    dfs(root);
    printf("%0.2lf %d", P*pow(1+r/100, max_cnt), tol_cnt);
    return 0;
}