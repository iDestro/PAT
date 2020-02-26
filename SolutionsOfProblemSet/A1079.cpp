/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 08:46:24
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-27 09:17:24
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
    int height;
    int flag;
    vector<int> childs;
    Node() {
        this -> flag = false;
    }
}nodes[100005];
int N;
double P, r, ans = 0;

void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    nodes[root].height = 0;
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        if (nodes[front].flag != true) {
            for (int i = 0; i < nodes[front].childs.size(); i++) {
                int child = nodes[front].childs[i];
                nodes[child].height = nodes[front].height+1;
                Q.push(child);
            }
        } else {
            ans += nodes[front].childs[0]*pow((1+r/100), nodes[front].height)*P;
        }
    }
}

int main() {
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        int num, temp;
        cin >> num;
        if (num == 0) {
            cin >> temp;
            nodes[i].childs.push_back(temp);
            nodes[i].flag = true;
        } else {
            for (int j = 0; j < num; j++) {
                cin >> temp;
                nodes[i].childs.push_back(temp);
            }
        }
    }
    levelOrder(0);
    printf("%0.1lf", ans);
    return 0;
}