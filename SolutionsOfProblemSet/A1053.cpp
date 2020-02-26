/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-24 11:17:46
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-24 18:17:41
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

int N, M, K, num, temp, id, tempWeight = 0;

struct Node {
    int id;
    int w;
    vector<int> childs;
}nodes[100];



void dfs(int root) {
    tempWeight += nodes[root].w;
    ans.push_back(nodes[root].w);
    if (tempWeight == K && nodes[root].childs.size() == 0) {
        int i;
        for (i = 0; i < ans.size()-1; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[i]);
    }
    for (int i = 0; i < nodes[root].childs.size(); i++) {
        dfs(nodes[root].childs[i]);
    }
    ans.pop_back();
    tempWeight -= nodes[root].w;
}

bool cmp(int a, int b) {
    return nodes[a].w > nodes[b].w;
}


int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        nodes[i].id = i;
        scanf("%d", &nodes[i].w);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &id, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &temp);
            nodes[id].childs.push_back(temp);
        }
        sort(nodes[id].childs.begin(), nodes[id].childs.end(), cmp);
    }
    dfs(0);
    return 0;
}