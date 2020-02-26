/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-20 09:24:08
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 09:35:35
 */
#include <iostream>
#define maxn 30
#include <vector>
using namespace std;
vector<int> temp, ans;
int a[maxn];
int N, K, max_squ_sum, x;

void dfs(int index, int squSum, int cnt, int sum) {
    if (cnt == K) {
        if (squSum > max_squ_sum && sum == x) {
            max_squ_sum = squSum;
            ans = temp;
        }
        return;
    }
    if (index == N || cnt > K || sum > x) return;
    temp.push_back(a[index]);
    dfs(index+1, squSum+a[index]*a[index], cnt+1, sum+a[index]);
    temp.pop_back();
    dfs(index+1, squSum, cnt+1, sum);
}

int main() {
    cin >> N >> K >> x;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    return 0;
}