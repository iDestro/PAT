/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-19 10:54:33
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-19 18:27:01
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 100000
using namespace std;

struct Node {
    int addr;
    int key;
    int next;
    int flag;
}nodes[MAXN];

int cmp(Node a, Node b) {
    if (a.flag != b.flag) {
        return a.flag < b.flag;
    } else {
        return a.key < b.key;
    }
}


int main() {
    int N, S, addr, key, next, count = 0;
    cin >> N >> S;
    for (int i = 0; i < MAXN; i++) {
        nodes[i].flag = MAXN;
    }
    for (int i = 0; i < N; i++) {
        cin >> addr >> key >> next;
        nodes[addr].addr = addr;
        nodes[addr].key = key;
        nodes[addr].next = next;
    }
    for (int i = S; i != -1; i = nodes[i].next) {
        nodes[i].flag = -1;
        count++;
    }
    if (count == 0) {
        printf("0 -1");
        return 0;
    }
    sort(nodes, nodes+MAXN, cmp);
    S = nodes[0].addr;
    printf("%d %05d\n", count, S);
    for (int i = 0; i < count-1; i++) {
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i+1].addr);
    }
    printf("%05d %d %d", nodes[count-1].addr, nodes[count-1].key, -1);
    return 0;
}