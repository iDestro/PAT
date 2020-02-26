/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-06 23:53:43
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-30 18:44:49
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct n{
    int idx, data, height;
    struct n *left, *right;
}Node;

Node *newNode(int x) {
    Node *node = new Node;
    node -> height = 1;
    node -> left = node -> right = NULL;
    node -> data = x;
    return node;
}

int getHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return root -> height;
}

int getBalanceFactor(Node *root) {
    return getHeight(root -> left)-getHeight(root -> right);
}

void updateHeight(Node *&root) {
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

void L(Node *&root) {
    Node *temp = root -> right;
    root -> right = temp -> left;
    temp -> left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node *&root) {
    Node *temp = root -> left;
    root -> left = temp -> right;
    temp -> right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node *&root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (root -> data > x) {
        insert(root -> left, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root -> left) == 1) {
                R(root);
            } else if (getBalanceFactor(root -> left) == -1) {
                L(root -> left);
                R(root);
            }
        }
    } else {
        insert(root -> right, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root -> right) == -1) {
                L(root);
            } else if (getBalanceFactor(root -> right) == 1) {
                R(root -> right);
                L(root);
            }
        }
    }
}

Node *create(vector<int> A) {
    Node *root = NULL;
    for (int i = 0; i < A.size(); i++) {
        insert(root, A[i]);
    }
    return root;
}

int cnt = 1;

bool flag = true;

void bfs(Node *root) {
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *front = Q.front();
        if (cnt != front -> idx) {
            flag = false;
        }
        cnt++;
        Q.pop();
        cout << front -> data;
        if (front -> left != NULL) {
            Q.push(front -> left);
        }
        if (front -> right != NULL) {
            Q.push(front -> right);
        }
        if (!Q.empty()) {
            cout << " ";
        }
    }
}

void preOrder(Node *&root, int x) {
    if (root != NULL) {
        root -> idx = x;
        preOrder(root -> left, 2*x);
        preOrder(root -> right, 2*x+1);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Node *root = create(A);
    preOrder(root, 1);
    bfs(root);
    cout << endl;
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}