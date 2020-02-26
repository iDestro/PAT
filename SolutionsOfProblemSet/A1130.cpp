/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-09 00:33:45
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-11 21:43:46
 */
#include <iostream>
#define maxn 25
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct Node {
    string data;
    int left, right;
}nodes[maxn];


bool vis[maxn] = {false};

string dfs(int root) {
    if (nodes[root].left == -1 && nodes[root].right == -1) {
        return nodes[root].data;
    }
    if (nodes[root].left == -1 && nodes[root].right != -1) {
        return "(" + nodes[root].data + dfs(nodes[root].right) + ")";
    }
    if (nodes[root].left != -1 && nodes[root].right != -1) {
        return "(" + dfs(nodes[root].left) + nodes[root].data + dfs(nodes[root].right) +")";
    }
    return "";
}

int main() {
    int N, root = 1;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nodes[i].data >> nodes[i].left >> nodes[i].right;
        if (nodes[i].left != -1) vis[nodes[i].left] = true;
        if (nodes[i].right != -1) vis[nodes[i].right] = true;
    }
    while (vis[root] == true) root++;
    string res = dfs(root);
    if (res[0] == '(') res = res.substr(1, res.size()-2);
    cout << res;
}

