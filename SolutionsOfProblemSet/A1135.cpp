/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-12 00:35:11
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-13 00:34:53
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

bool flag = true;
vector<Node*> path;
vector<int> pre;
int cnt = -1;

Node *build(Node *root , int v) {
    if (root == NULL) {
        root = new Node;
        root -> data = v;
        root -> left = root -> right = NULL;
    } else if (abs(root -> data) >= abs(v)) {
        root -> left = build(root -> left, v);
    } else {
        root -> right = build(root -> right, v);
    }
    return root;
}

bool judge1(Node *root) {
    if (root == NULL) {
        return true;
    }
    if (root -> data < 0) {
        if (root -> left != NULL && root -> left -> data < 0) return false;
        if (root -> right != NULL && root -> right -> data < 0) return false;
    }
    return judge1(root -> left) && judge1(root -> right);
}

int getNum(Node *root) {
    if (root == NULL) {
        return 1;
    }
    int left = getNum(root -> left);
    int right = getNum(root -> right);
    return root -> data > 0 ? max(left, right)+1 : max(left, right);
}

bool judge2(Node *root) {
    if (root == NULL) {
        return true;
    }
    int left = getNum(root -> left);
    int right = getNum(root -> right);
    if (left != right) return false;
    return judge2(root -> left) && judge2(root -> right);
}

int main() {


    int N, K;
    cin >> K;
    while (K--) {
        cin >> N;
        pre.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> pre[i];
        }
        Node *root = NULL;
        for (int i = 0; i < pre.size(); i++) {
            root = build(root, pre[i]);
        }
        if (root -> data > 0 && judge1(root) && judge2(root)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}