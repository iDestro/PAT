/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-23 22:37:26
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-23 23:45:03
 */

#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

double res(set<int> a, set<int> b) {
    double cnt = 0;
    if (a.size() < b.size()) {
        swap(a, b);
    }
    for (set<int> :: iterator iter = b.begin(); iter != b.end(); iter++) {
        int tempSize = a.size();
        a.insert(*iter);
        if (tempSize == a.size()) {
            cnt++;
        }
    }
    return cnt / a.size();
}

int main() {
    int N, M, K, temp;
    vector<double> ans;
    scanf("%d", &N);
    set<int> sets[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &temp);
            sets[i].insert(temp);
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%0.1f%c\n", res(sets[x-1], sets[y-1])*100, '%');
    }
    return 0;
}