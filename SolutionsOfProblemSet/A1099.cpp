#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    int lchild;
    int rchild;

}nodes[101];
int N, A[101], cnt = 0;

void inOrder(int root) {
    if (root != -1) {
        inOrder(nodes[root].lchild);
        nodes[root].data = A[cnt++];
        inOrder(nodes[root].rchild);
    }
}

int num = 0;

void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        cout << nodes[front].data;
        num++;
        if (num < N) {
            cout << " ";
        }
        if (nodes[front].lchild != -1) {
            Q.push(nodes[front].lchild);
        }
        if (nodes[front].rchild != -1) {
            Q.push(nodes[front].rchild);
        }

    }
}

int main() {
    cin >> N;
    int l, r;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        nodes[i].lchild = l;
        nodes[i].rchild = r;
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A+N);
    inOrder(0);
    levelOrder(0);
    return 0;
}