/*
 * @Descripttion: liucuo's version
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-21 09:19:09
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-21 09:32:35
 */

#include <iostream>
#include <stack>
using namespace std;
int main() {
    int M, N, K, current;
    cin >> M >> N >> K;
    int a[N+1];
    for (int i = 0; i < K; i++) {
        for (int j = 1; j < N+1; j++) {
            cin >> a[j];
        }
        current = 1;
        stack<int> S;
        for (int j = 1; j < N+1; j++) {
            S.push(j);
            if (S.size() > M) break;
            while (!S.empty() && S.top() == a[current]) {
                S.pop();
                current++;
            }
        }
        current == N+1 ? cout << "YES\n" : cout << "NO\n";
    }
}