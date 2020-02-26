/*
 * @Descripttion: 1103 Integer Factorization (22/30 分)
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-21 14:08:43
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-22 10:14:52
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, K, P;
vector<int> ans, temp, v;
int ansSum = -1;
void dfs(int cnt, int sum, int sumQu, int num) {
    if (cnt == K) {
        if (sumQu == N) {
            if (sum > ansSum) {
                ans = temp;
                ansSum = sum;
            } else if (sum == ansSum) {
                bool flag = false;
                for (int i = 0; i < ans.size(); i++) {
                    if (temp[i] > ans[i]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    ans = temp;
                }
            }
        }
        return;
    }
    if (sumQu + pow(num, P) > N || cnt > K) {
        return;
    }
    dfs(cnt, sum, sumQu, num+1);
    if (sumQu + pow(num, P) <= N) {
        temp.push_back(num);
        dfs(cnt+1, sum+num, sumQu + pow(num, P), num);
        temp.pop_back();
        
        temp.push_back(num);
        dfs(cnt+1, sum+num, sumQu + pow(num, P), num+1);
        temp.pop_back();
    }
}

int main() {
    cin >> N >> K >> P;
    dfs(0, 0, 0, 1);
    sort(ans.begin(), ans.end());
    if (ans.size() > 0) {
        cout << N << " = ";
        for (int i = ans.size()-1; i >= 1; i--) {
            cout << ans[i] << "^" << P << " + ";
        }
        cout << ans[0] << "^" << P;
    } else {
        cout << "Impossible";
    }
    return 0;
}