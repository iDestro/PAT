/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 10:12:42
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 12:32:53
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int *father;
bool *flag;
int ans[1001] = {0};

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
        father[Fu] = Fv;
    }
}

void init() {
    father = new int[1001];
    flag = new bool[1001];
    for (int i = 0; i < 1001; i++) {
        father[i] = i;
        flag[i] = false;
    }
}

int main() {
    int N, K, u, v, cnt = 0;
    scanf("%d", &N);
    vector<int> record[N];
    int mark[1001][1001] = {0};
    init();
    for (int i = 0; i < N; i++) {
        scanf("%d: %d", &K, &u);
        record[i].push_back(u);
        flag[u] = true;
        for (int j = 0; j < K-1; j++) {
            scanf("%d", &v);
            record[i].push_back(v);
            flag[v] = true;
            Union(u, v);
        }
    }
    for (int i = 1; i < 1001; i++) {
        if (flag[i] && father[i] == i) {
            cnt++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < record[i].size(); j++) {
            int temp = Find(record[i][j]);
            if (!mark[i][temp]) {
                ans[temp]++;
                mark[i][temp] = 1;
            }
        }
    }
    sort(ans, ans+1001);
    cout << cnt << endl;
    for (int i = 1000; i > 1000-cnt+1; i--) {
        cout << ans[i] << " ";
    }
    cout << ans[1000 - cnt+1];
}
