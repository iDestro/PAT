/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-08 22:48:48
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-08 22:55:24
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool judge(vector<int> dot) {
    for (int i = 0; i < dot.size(); i++) {
        for (int j = i+1; j < dot.size(); j++) {
            if (abs(j-i) == abs(dot[j]-dot[i]) || dot[j] == dot[i]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int N, K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        vector<int> dot(K);
        for (int j = 0; j < K; j++) {
            cin >> dot[j];
        }
        if (judge(dot)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}