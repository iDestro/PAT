/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-24 18:50:01
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-24 23:44:30
 */

#include <cstdio>
#include <vector>
using namespace std;


vector<int> pre, preM, post, postM, origin;

int N, temp;

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

void insert(Node *&root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (root -> data > x) {
        insert(root -> lchild, x);
    } else {
        insert(root -> rchild, x);
    }
}

void preOrder(Node *&root) {
    if (root != NULL) {
        pre.push_back(root -> data);
        preOrder(root -> lchild);
        preOrder(root -> rchild);
    }
}

void preMOrder(Node *&root) {
    if (root != NULL) {
        preM.push_back(root -> data);
        preMOrder(root -> rchild);
        preMOrder(root -> lchild);
    }
}

void postOrder(Node *&root) {
    if (root != NULL) {
        postOrder(root -> lchild);
        postOrder(root -> rchild);
        post.push_back(root -> data);
    }
}

void postMOrder(Node *&root) {
    if (root != NULL) {
        postMOrder(root -> rchild);
        postMOrder(root -> lchild);
        postM.push_back(root -> data);
    }
}

int main() {
    scanf("%d", &N);
    bool flag = true;
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        origin.push_back(temp);
        insert(root, temp);
    }

    preOrder(root);
    preMOrder(root);
    postOrder(root);
    postMOrder(root);

    if (origin == pre) {
        printf("YES\n");
        int i;
        for (i = 0; i < post.size()-1; i++) {
            printf("%d ", post[i]);
        }
        printf("%d", post[i]);
    } else if (origin == preM) {
        printf("YES\n");
        int i;
        for (i = 0; i < postM.size()-1; i++) {
            printf("%d ", postM[i]);
        }
        printf("%d", postM[i]);
    } else {
        printf("NO");
    }
    return 0;
}