#include <iostream> 
#include <queue>
#include <cstdio>
#define maxn 10
using namespace std;

struct Node {
    int data;
    int lchild;
    int rchild;
}nodes[maxn];
int N, visited[maxn] = {0};

int trans(char ch) {
    if (ch >= '0' && ch <= '9') {
        visited[ch-'0'] = 1;
        return ch - '0';
    } else {
        return -1;
    }
}

int cnt = 0;
void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        cnt++;
        cout << front;
        if (cnt < N) {
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

int cnt1 = 0;

void inOrder(int root) {
    if (root != -1) {
        inOrder(nodes[root].lchild);
        cout << root;
        cnt1++;
        if (cnt1 < N) {
            cout << " ";
        }
        inOrder(nodes[root].rchild);
    }
}

void swap(int root) {
    if (root != -1) {
        int temp = nodes[root].lchild;
        nodes[root].lchild = nodes[root].rchild;
        nodes[root].rchild = temp;
        swap(nodes[root].lchild);
        swap(nodes[root].rchild);
    }
}

int main() {
    char l, r;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++) {
        scanf("%c %c", &l, &r);
        getchar();
        nodes[i].lchild = trans(l);
        nodes[i].rchild = trans(r);
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            root = i;
            break;
        }
    }
    swap(root);
    levelOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}