/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-18 01:15:46
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-18 23:16:54
 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool isMin = 1, isMax = 1;
int *a;
vector<int> path;
int n;

void dfs(int root) {
    if (root*2 > n) {
        if (root <= n) {
            for (int i = 0; i < path.size(); i++) {
                printf("%d", path[i]);
                if (i != path.size()-1) {
                    cout << " ";
                }
            }
            printf("\n");
        }
    } else {
        path.push_back(a[root*2+1]);
        dfs(root*2+1);
        path.pop_back();
        path.push_back(a[root*2]);
        dfs(root*2);
        path.pop_back();
    }
}
int main() {
    cin >> n;
    a = new int[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    path.push_back(a[1]);
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (a[i/2] > a[i]) isMin = 0;
        if (a[i/2] < a[i]) isMax = 0;
    }
    if (isMin == 1) {
        printf("Min Heap");
    } else if (isMax == 1) {
        printf("Max Heap");
    } else {
        printf("Not Heap");
    }
    return 0;
}