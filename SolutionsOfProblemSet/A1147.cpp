/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-16 00:43:12
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-16 01:19:21
 */
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int val, left, right;
    Node() {
        this -> left = this -> right = -1;
    }
}nodes[1005];
int m, n, arr[1005];
int cnt;

void levelOrder(int root) {
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        nodes[front].val = arr[cnt++];
        if (2*front <= n) {
            nodes[front].left = 2*front;
            Q.push(2*front);
        }
        if (2*front+1 <= n) {
            nodes[front].right = 2*front+1;
            Q.push(2*front+1);
        }
    }
}
int num;
void postOrder(int root) {
    if (root != -1) {
        postOrder(nodes[root].left);
        postOrder(nodes[root].right);
        printf("%d", nodes[root].val);
        num++;
        if (num < n) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
bool ismin, ismax;

void minheap(int root) {
    if (root != -1) {
        int left = nodes[root].left;
        int right = nodes[root].right;
        if (left != -1 && nodes[root].val > nodes[left].val) {
            ismin = false;
        }
        if (right != -1 && nodes[root].val > nodes[right].val) {
            ismin = false;
        }
        minheap(left);
        minheap(right);
    }
}

void maxheap(int root) {
    if (root != -1) {
        int left = nodes[root].left;
        int right = nodes[root].right;
        if (left != -1 && nodes[root].val < nodes[left].val) {
            ismax = false;
        }
        if (right != -1 && nodes[root].val < nodes[right].val) {
            ismax = false;
        }
        maxheap(left);
        maxheap(right);
    }
}

int main() {
    cin >> m >> n;
    while (m--) {
        cnt = 1;
        num = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        levelOrder(1);
        ismax = true, ismin = true;
        minheap(1);
        maxheap(1);
        if (ismax) {
            printf("Max Heap\n");
        }
        if (ismin) {
            printf("Min Heap\n");
        }
        if (!ismin && !ismax) {
            printf("Not Heap\n");
        }
        postOrder(1);
    }
    return 0;
}