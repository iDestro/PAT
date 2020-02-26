/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 11:10:04
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-27 11:51:24
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Node {
    vector<int> childs;
}nodes[100005];

int N, cnt = 0, min_cnt = 100005, tot_cnt = 0;
double P, r;

void dfs(int root) {
    if (nodes[root].childs.size() == 0) {
        if (cnt < min_cnt) {
            min_cnt = cnt;
            tot_cnt = 1;
        } else if (cnt == min_cnt) {
            tot_cnt++;
        }
    }
    for (int i = 0; i < nodes[root].childs.size(); i++) {
        cnt++;
        dfs(nodes[root].childs[i]);
        cnt--;
    }
}

int main() {
    int num, temp;
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> temp;
            nodes[i].childs.push_back(temp);
        }
    }
    dfs(0);
    printf("%0.4lf %d", P*pow((1+r/100), min_cnt), tot_cnt);
}