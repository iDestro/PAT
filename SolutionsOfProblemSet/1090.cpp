/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 09:18:10
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-27 10:04:19
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int height;
    vector<int> childs;
}nodes[100005];

int N, cnt = 0, tol_cnt = 0, max_cnt = 0;
double P, r, max;

void dfs(int root) {
    cout << root << endl;
    for (int i = 0; nodes[root].childs.size(); i++) {
        dfs(nodes[root].childs[i]);
    }
}

int main() {
    int temp, root;
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        nodes[temp].childs.push_back(i);
        if (temp == -1) {
            root = i;
        }
    }
    cout << root << endl;
    // dfs(root);
    return 0;
}