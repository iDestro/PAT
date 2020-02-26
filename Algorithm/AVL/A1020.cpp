#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

Node *newNode(int x) {
    Node *node = new Node;
    node -> data = x;
    node -> lchild = node -> rchild = NULL;
    return node;
}

int *post, *in, N;

Node *create(int postL, int postH, int inL, int inH) {
    if (postL > postH) {
        return NULL;
    }
    Node *root = newNode(post[postH]);
    int k;
    for (k = inL; in[k] != post[postH]; k++);
    int leftNum = k - inL;
    root -> lchild = create(postL, postL+leftNum-1, inL, inL+leftNum-1);
    root -> rchild = create(postL+leftNum, postH-1, inL+leftNum+1, inH);
    return root;
}

int cnt = 0;

void levelOrder(Node *&root) {
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *front = Q.front();
        Q.pop();
        cnt++;
        cout << front -> data;
        if (cnt < N) {
            cout << " ";
        }
        if (front -> lchild != NULL) {
            Q.push(front -> lchild);
        }
        if (front -> rchild != NULL) {
            Q.push(front -> rchild);
        }
    }
}

int main() {
    cin >> N;
    post = new int[N];
    in = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    Node *root = create(0, N-1, 0, N-1);
    levelOrder(root);
    return 0;
}