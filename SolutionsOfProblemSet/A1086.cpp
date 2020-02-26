/*
 * @Descripttion: 1086 Tree Traversals Again (21/25 分)
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-24 10:12:56
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-24 11:01:11
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#define maxn 50
using namespace std;

int pre[50];
int in[50];
stack<int> S;

int N;
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

node *create(int prel, int preh, int inl, int inh) {
    if (prel > preh) {
        return NULL;
    }
    node *root = new node;
    root -> data = pre[prel];
    int k;
    for (k = inl; in[k] != pre[prel]; k++);
    int leftNum = k - inl;
    root -> lchild = create(prel+1, prel+leftNum, inl, inl+leftNum-1);
    root -> rchild = create(prel+leftNum+1, preh, inl+leftNum+1, inh);
    return root;
}

int cnt = 0;

void post(node *&root) {
    if (root != NULL) {
        post(root -> lchild);
        post(root -> rchild);
        printf("%d", root->data);
        cnt++;
        if (cnt < N) {
            printf(" ");
        }
    }
}

int main() {
    int j = 0, k = 0;
    scanf("%d", &N);
    string op;
    getchar();
    for (int i = 0; i < 2*N; i++) {
        getline(cin, op);
        if (op[1] == 'u') {
            pre[j++] = op[5]-'0';
            S.push(op[5]-'0');
        } else {
            in[k++] = S.top();
            S.pop();
        }
    }
    node *root = create(0, N-1, 0, N-1);
    post(root);
    return 0;
}