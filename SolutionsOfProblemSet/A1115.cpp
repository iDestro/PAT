#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}Node;

Node* newNode(int x) {
    Node *node = new Node;
    node -> data = x;
    node -> left = node -> right = NULL;
    return node;
}

void insert(Node *&root, int x) {
    if (root == NULL) {
        Node *node = newNode(x);
        root = node;
        return;
    }
    if (root -> data >= x) {
        insert(root -> left, x);
    } else {
        insert(root -> right, x);
    }
}

vector<int> ans;

void bfs(Node *root) {
    queue<Node*> Q;
    Q.push(root);
    int cnt = 0;
    Node *lastNode = root;
    while (!Q.empty()) {
        Node *front = Q.front();
        Q.pop();
        cnt++;
        if (front -> left != NULL) {
            Q.push(front -> left);
        }
        if (front -> right != NULL) {
            Q.push(front -> right);
        }
        if (front == lastNode) {
            ans.push_back(cnt);
            cnt = 0;
            lastNode = Q.back();
        }
    }
}

int main() {
    int N;
    Node *root = NULL;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        insert(root, temp);
    }
    // insert(root, 25);
    bfs(root);
    int size = ans.size();
    cout << ans[size-1] << " + " << ans[size-2] << " = " << ans[size-1]+ans[size-2];
    return 0;
}