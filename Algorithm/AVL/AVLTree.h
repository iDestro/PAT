/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 08:43:23
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 09:13:36
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int height;
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

int getHeight(Node *&root) {
    if (root == NULL) return 0;
    return root -> height;
}

void updateHeight(Node *&root) {
    root -> height =  max(getHeight(root -> lchild), getHeight(root -> rchild));
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

Node *newNode(int x) {
    Node *node = new Node;
    node -> data = x;
    node -> height = 1;
    node -> lchild = node -> rchild = NULL;
    return node;
}

void insert(Node *&root, int v) {
    if (root != NULL) {
        root = newNode(v);
    }
    if (root -> data > v) {
        insert(root -> lchild, v);
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
        insert(root -> rchild, v);
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