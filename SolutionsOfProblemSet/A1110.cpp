#include <iostream>
#include <queue>
using namespace std;
const int maxn = 25;

struct Node {
    int idx;
    int data;
    int l, r;
}nodes[maxn];
bool vis[maxn] = {false};

void preOrder(int root, int index) {
    if (root != -1) {
        nodes[root].idx = index;
        preOrder(nodes[root].l, index*2);
        preOrder(nodes[root].r, index*2+1);
    }
}
int cnt = 1;
int lastNode;
bool bfs(int root) {
    queue<Node> Q;
    Q.push(nodes[root]);
    while (!Q.empty()) {
        Node front = Q.front();
        Q.pop();
        lastNode = front.data;
        if (front.idx != cnt) {
            return false;
        }
        cnt++;
        if (front.l != -1) {
            Q.push(nodes[front.l]);
        }
        if (front.r != -1) {
            Q.push(nodes[front.r]);
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string l, r;
        cin >> l >> r;
        nodes[i].data = i;
        if (l[0] == '-') {
            nodes[i].l = -1;
        } else {
            nodes[i].l = stoi(l);
            vis[nodes[i].l] = true;
        }
        if (r[0] == '-') {
            nodes[i].r = -1;
        } else {
            nodes[i].r = stoi(r);
            vis[nodes[i].r] = true;
        }
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    preOrder(root, 1);
    if (bfs(root)) {
        cout << "YES " << lastNode;
    } else {
        cout << "NO " << root;
    }
    return 0;
}