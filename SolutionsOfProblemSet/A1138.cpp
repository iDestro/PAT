/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-13 23:42:44
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-13 23:54:30
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in, post;
struct Node {
    int val;
    struct Node *left, *right;
    Node(int v) {
        this -> val = v;
        this -> left = this -> right = NULL;
    }
};

Node *create(int preL, int preH, int inL, int inH) {
    if (preL > preH) {
        return NULL;
    }
    Node *root = new Node(pre[preL]);
    int k;
    for (k = inL; in[k] != pre[preL]; k++);
    int leftNum = k-inL;
    root -> left = create(preL+1, preL+leftNum, inL, inL+leftNum-1);
    root -> right = create(preL+leftNum+1, preH, inL+leftNum+1, inH);
    return root;
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root -> left);
        postOrder(root -> right);
        post.push_back(root -> val);
    }
}

int main() {
    int N;
    cin >> N;
    pre.resize(N);
    in.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    Node *root = create(0, N-1, 0, N-1);
    postOrder(root);
    cout << post[0];
    return 0;
}