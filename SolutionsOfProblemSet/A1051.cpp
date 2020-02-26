/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-20 10:38:27
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-20 12:30:47
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int main() {
    int M, N, K, x;
    bool flag = false;
    queue<int> Q;
    stack<int> S;
    vector<string> res;
    int a[N+1];
    cin >> M >> N >> K;
    for (int i = 1; i <= K; i++) {
        flag = false;
        for (int j = 1; j <= N; j++) {
            cin >> x;
            Q.push(x);
        }
        for (int j = 1; j <= N; j++) {
            if (Q.front() != j) {
                S.push(j);
            } else {
                S.push(j);
                if (S.size() > M) {
                    flag = true;
                    break;
                }
                if (!S.empty()) {
                    while (!S.empty() && !Q.empty()) {
                        if (S.top() == Q.front()) {
                            S.pop();
                            Q.pop();
                        } else {
                            break;
                        }
                    }
                } else {
                    Q.pop();
                    S.pop();
                }
            }
        }
        if (Q.size() > 0 || flag) {
            res.push_back("NO");
        } else {
            res.push_back("YES");
        }
        while (!S.empty()) {
            S.pop();
        }
        while (!Q.empty()) {
            Q.pop();
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}