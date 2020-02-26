/*
 * @Descripttion: 分值23/25，不知道什么回事，感觉是对的，哈哈哈, 解决了,输出格式错了，后面应该是%05d
 * @version: 1
 * @Author: iDestro
 * @Date: 2019-07-19 09:45:22
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-19 10:49:26
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    char ch;
    int next;
}Node;

Node nodes[99999];

int match(int A, int B, int offset) {
    while (offset-- > 0) {
        A = nodes[A].next;
    }
    int res = -1;
    while (A != -1 && B != -1) {
        if (A == B) {
            res = A;
            break;
        } else {
            A = nodes[A].next;
            B = nodes[B].next;
        }
    }
    return res;
}

int main() {
    int A, B, N, addr, next, Alen = 0, Blen = 0, p;
    char ch;
    cin >> A >> B >> N;
    for (int i = 0; i < N; i++) {
        cin >> addr >> ch >> next;
        nodes[addr].ch = ch;
        nodes[addr].next = next;
    }
    p = A;
    while (p != -1) {
        p = nodes[p].next;
        Alen++;
    }
    p = B;
    while (p != -1) {
        p = nodes[p].next;
        Blen++;
    }
    cout << (Alen > Blen ? match(A, B, Alen - Blen) : match(B, A, Blen - Alen));
    return 0;

}