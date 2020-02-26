/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 10:02:28
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 10:10:03
 */

#include <iostream>
using namespace std;

int *father;

int Find(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}

void Union(int u, int v) {
    int Fu = Find(u);
    int Fv = Find(v);
    if (Fu != Fv) {
        father[Fv] = Fu;
    }
}

int main() {
    int N, M, u, v, cnt = 0;
    scanf("%d%d", &N, &M);
    father = new int[N];
    for (int i = 0; i < N; i++) {
        father[i] = i;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        Union(u, v);
    }
    for (int i = 0; i < N; i++) {
        if (father[i] == i) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}