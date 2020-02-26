/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-11 23:07:50
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-12 00:06:53
 */
#include <iostream>
#define maxn 100005
#define INF 1000000000
#include <algorithm>
using namespace std;

struct node {
    int data, next, flag, idx, addr;
    node() {
        this -> flag = 0;
    }
}nodes[maxn];

bool cmp(node a, node b) {
    if (a.flag != b.flag) {
        return a.flag > b.flag;
    } else if ( a.data * b.data < 0) {
        return a.data < b.data;
    } else if (a.data * b.data == 0 && (a.data < 0 || b.data < 0)) {
        return a.data < b.data;
    } else {
        return a.idx < b.idx;
    }
}

int k;

bool cmp1(node a, node b) {
    if (a.data > k && b.data > k) {
        return a.idx < b.idx;
    } else if (a.data < k && b.data < k){
        return a.idx < b.idx;
    } else {
        return a.data < b.data;
    }
}

int main() {
    int n, addr, root, cnt = 0;
    cin >> root >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }
    for (int x = root; x != -1; x = nodes[x].next) {
        nodes[x].flag = 1;
        nodes[x].idx = cnt++;
    }
    sort(nodes, nodes+maxn, cmp);
    int kidx = 0;
    while (nodes[kidx].data < 0) kidx++;
    sort(nodes+kidx, nodes+n, cmp1);
    nodes[n-1].next = -1;
    for (int i = 0; i < n-1; i++) {
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i+1].addr);
    }
    printf("%05d %d -1", nodes[n-1].addr, nodes[n-1].data);
    return 0;
}