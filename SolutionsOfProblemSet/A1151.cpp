/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-17 00:58:54
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-17 01:52:26
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre, in;


struct Node {
    int val, vc;
    struct Node *left, *right;
    Node() {
        this -> vc = 0;
    }
};

Node *newNode(int x) {
    Node *node = new Node;
    node -> val = x;
    node -> left = node -> right = NULL;
    return node;
}
Node *build(int preL, int preH, int inL, int inH) {
    if (preL > preH) {
        return NULL;
    }
    Node *root = newNode(pre[preL]);
    int k;
    for (k = inL; in[k] != pre[preL]; k++);
    int leftNum = k - inL;
    root -> left = build(preL+1, preL+leftNum, inL, inL+leftNum-1);
    root -> right = build(preL+leftNum+1, preH, inL+leftNum+1, inH);
    return root;
}

bool isvalid = false;

void search(Node *root, int p) {
    if (root != NULL) {
        if (root -> val == p) {
            isvalid = true;
        }
        search(root -> left, p);
        search(root -> right, p);
    }
}

vector<int> cnt;

int ans = -1;

bool LCA(Node *root, int p, int q) {
    if (root == NULL) {
        return false;
    }
    int left = LCA(root -> left, p, q) ? 1:0;
    int right = LCA(root -> right, p, q) ? 1:0;
    int mid = (root -> val == p || root -> val == q) ? 1:0;
    if (left + right + mid >= 2) {
        ans = root -> val;
    }
    return (left + right + mid) > 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    pre.resize(m);
    in.resize(m);
    cnt.resize(m);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < m; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> pre[i];
    }
    Node *root = build(0, m-1, 0, m-1);
    for (int i = 0; i < n; i++) {
        int u, v;
        bool u_, v_;
        cin >> u >> v;
        isvalid = false;
        search(root, u);
        u_ = isvalid;
        isvalid = false;
        search(root, v);
        v_ = isvalid;
        if (!u_ && !v_) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (!u_) {
            printf("ERROR: %d is not found.\n", u);
        } else if (!v_) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            ans = -1;
            if (u != v) {
                LCA(root, u, v);
            } else {
                ans = u;
            }
            if (ans == u) {
                printf("%d is an ancestor of %d.\n", u, v);
            } else if (ans == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, ans);
            }
        }
    }
}