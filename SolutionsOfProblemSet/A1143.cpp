/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-15 00:08:52
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-15 20:27:37
 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

void build(Node *&root, int x) {
    if (root == NULL) {
        root = new Node;
        root -> val = x;
        root -> left = root -> right = NULL;
    } else if (root -> val > x) {
        build(root -> left, x);
    } else {
        build(root -> right, x);
    }
}

bool search(Node *root, int x) {
    if (root == NULL) {
        return false;
    } else if (root -> val == x) {
        return true;
    } else if (root -> val > x) {
        return search(root -> left, x);
    } else {
        return search(root -> right, x);
    }
}

int LCA(Node *root, int a, int b) {
    if (root == NULL) {
        return -1;
    }
    if (root -> val > a && root -> val > b) {
        return LCA(root -> left, a, b);
    } else if (root -> val <= a && root -> val <= b) {
        return LCA(root -> right, a, b);
    } else {
        return root -> val;
    }
}

// void inOrder(Node *root) {
//     if (root != NULL) {
//         inOrder(root -> left);
//         cout << root -> val << " ";
//         inOrder(root -> right);
//     }
// }

int main() {
    int m, n, temp, u, v;
    Node *root = NULL;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        build(root, temp);
    }
    // inOrder(root);
    vector<int> error;
    for (int i = 0; i < m; i++) {
        error.clear();
        cin >> u >> v;
        if (!search(root, u)){
            error.push_back(u);
        }
        if (!search(root, v)) {
            error.push_back(v);
        }
        if (error.size() == 0) {
            int ans = LCA(root, u, v);
            if (ans == u) {
                printf("%d is an ancestor of %d.\n", u, v);
            } else if (ans == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, ans);
            }
        } else if (error.size() == 1){
            printf("ERROR: %d is not found.\n", error[0]);
        } else if (error.size() == 2) {
            printf("ERROR: %d and %d are not found.\n", error[0], error[1]);
        }
    }
    return 0;
}