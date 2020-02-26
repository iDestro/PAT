#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int height;
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

Node *newNode(int x) {
    Node *node = new Node;
    node -> data = x;
    node -> height = 1;
    node -> lchild = node -> rchild = NULL;
    return node;
}

int getHeight(Node *root) {
    if (root == NULL) return 0;
    return root -> height;
}

void updateHeight(Node *&root) {
    root -> height = max(getHeight(root -> lchild), getHeight(root -> rchild)) + 1;
}

int getBalanceFactor(Node *root) {
    return getHeight(root -> lchild) - getHeight(root -> rchild);
}

void L(Node *&root) {
    Node *temp = root -> rchild;
    root -> rchild = temp -> lchild;
    temp -> lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node *&root) {
    Node *temp = root -> lchild;
    root -> lchild = temp -> rchild;
    temp -> rchild = root;
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
        insert(root -> lchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root -> lchild) == 1) {
                R(root);
            } else if (getBalanceFactor(root -> lchild) == -1) {
                L(root -> lchild);
                R(root);
            }
        }
    } else {
        insert(root -> rchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root -> rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(root -> rchild) == 1) {
                R(root -> rchild);
                L(root);
            }
        }
    }
}

Node *create(int A[], int N) {
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        insert(root, A[i]);
    }
    return root;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Node *root = create(A, N);
    cout << root -> data;
}