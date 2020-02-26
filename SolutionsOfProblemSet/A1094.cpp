/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 10:37:18
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-27 11:09:53
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int height;
    vector<int> childs;
}nodes[100];

int N, M, cnt[100] = {0};

void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    nodes[root].height = 1;
    while(!Q.empty()) {
        int front = Q.front();
        Q.pop();
        cnt[nodes[front].height]++;
        int size = nodes[front].childs.size();
        for (int i = 0; i < size; i++) {
            int child = nodes[front].childs[i];
            nodes[child].height = nodes[front].height+1;
            Q.push(child);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int id, num, temp;
        cin >> id >> num;
        for (int j = 0; j < num; j++) {
            cin >> temp;
            nodes[id].childs.push_back(temp);
        }
    }
    levelOrder(1);
    int max_idx = 0;
    for (int i = 1; i < 100; i++) {
        if (cnt[i] > cnt[max_idx]) {
            max_idx = i;
        }
    }
    cout << cnt[max_idx] << " " << max_idx;
}