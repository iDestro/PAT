/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-26 11:13:06
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-26 11:20:01
 */

#include <iostream>
using namespace std;

int N, *father;

void init() {
    for (int i = 0; i < N; i++) {
        father[i] = i;
    }
}

int Find(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;

    }
    return x;
}

void Union(int u, int v) {
    int Fu = Find(u);
    int Fv = Find(v);
    if (Fu != Fv) {
        father[Fu] = Fv;
    }
}

int main() {
    cin >> N;
    father = new int[N];
    init();
    return 0;
}