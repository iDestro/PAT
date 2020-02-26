/*
 * @Descripttion: Reversing linked List
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-21 12:14:09
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-21 13:05:16
 */

#include <iostream>
#include <cstdio>
#define maxn 100000
#include <vector>
using namespace std;

struct Node{
    int addr, data, next;
}nodes[maxn];

int main() {
    int S, N, K, cnt = 0;
    cin >> S >> N >> K;
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr].addr = addr;
        nodes[addr].data = data;
        nodes[addr].next = next;
    }
    vector<Node> v;
    for (int i = S; i != -1; i = nodes[i].next) {
        v.push_back(nodes[i]);
    }
    for (int i = 0; i < v.size() - v.size() % K; i+=K) {
        for (int j = i; j < (2*i+K)/2; j++) {
            swap(v[j], v[2*i+K-1-j]);
        }
    }
    for (int i = 0; i < v.size()-1; i++) {
        printf("%05d %d %05d\n", v[i].addr, v[i].data, v[i+1].addr);
    }
    printf("%05d %d %d\n", v[v.size()-1].addr, v[v.size()-1].data, -1);
}