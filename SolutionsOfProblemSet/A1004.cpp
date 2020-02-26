#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int height;
    vector<int> childs;
}nodes[100];

int N, M, cnt[100] = {0}, max_height = 0;

void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    nodes[root].height = 0;
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        int size = nodes[front].childs.size();
        if (size == 0) {
            int height = nodes[front].height;
            if (height > max_height) {
                max_height = height;
            }
            cnt[nodes[front].height]++;
        } else {
            for (int i = 0; i < size; i++) {
                int child = nodes[front].childs[i];
                nodes[child].height = nodes[front].height + 1;
                Q.push(child);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    int parent, num, child;
    for (int i = 0; i < M; i++) {
        cin >> parent >> num;
        for (int j = 0; j < num; j++) {
            cin >> child;
            nodes[parent].childs.push_back(child);
        }
    }
    levelOrder(1);
    for (int i = 0; i <= max_height; i++) {
        cout << cnt[i];
        if (i != max_height) {
            cout << " ";
        }
    }
    return 0;
}