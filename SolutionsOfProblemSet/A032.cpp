/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-19 10:38:39
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-19 10:48:35
 */
#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    char ch;
    int next;
    bool flag;
}nodes[99999];

int main() {
    int A, B, N, addr, next;
    char ch;
    cin >> A >> B >> N;
    for (int i = 0; i < N; i++) {
        cin >> addr >> ch >> next;
        nodes[addr].ch = ch;
        nodes[addr].next = next;
        nodes[addr].flag = false;
    }
    while (A != -1) {
        nodes[A].flag = true;
        A = nodes[A].next;
    }
    while (B != -1) {
        if (nodes[B].flag) {
            printf("%05d", B);
            return 0;
        } else {
            B = nodes[B].next;
        }
    }
    printf("-1");
    return 0;
}