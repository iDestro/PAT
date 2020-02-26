/*
 * @Descripttion: 值的大小为10^4，且求绝对值，提示使用hash数组
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-21 13:05:53
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-21 13:53:28
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;

struct Node {
    int addr, data, next, order;
}nodes[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}
bool isExist[maxn] = {false};
int main() {
    int S, N, order = 0;
    scanf("%d%d", &S, &N);
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        scanf("%d%d%d", &addr, &data, &next);
        nodes[addr].addr = addr;
        nodes[addr].data = data;
        nodes[addr].next = next;
    }
    vector<Node> v, r;
    for (int i = S; i != -1; i = nodes[i].next) {
        nodes[i].order = order++;
        if (!isExist[abs(nodes[i].data)]) {
            v.push_back(nodes[i]);
            isExist[abs(nodes[i].data)] = true;
        } else {
            r.push_back(nodes[i]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    sort(r.begin(), r.end(), cmp);
    int i;
    for (i = 0; i < v.size()-1; i++) {
        printf("%05d %d %05d\n", v[i].addr, v[i].data, v[i+1].addr);
    }
    printf("%05d %d %d\n", v[i].addr, v[i].data, -1);
    if (r.size() > 0) {
        for (i = 0; i < r.size()-1; i++) {
            printf("%05d %d %05d\n", r[i].addr, r[i].data, r[i+1].addr);
        }
        printf("%05d %d %d\n", r[i].addr, r[i].data, -1);
    }
    return 0;
}