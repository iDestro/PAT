/*
 * @Descripttion: 1039 Course List for Student (25 分),书上用自己写的散列实现的
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-22 22:44:03
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-22 23:16:32
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    map<string, vector<int> > res;
    string name;
    for (int i = 0; i < K; i++) {
        int index, n;
        cin >> index >> n;
        for (int j = 0; j < n; j++) {
            cin >> name;
            if (res.find(name) == res.end()) {
                vector<int> temp;
                temp.push_back(index);
                res[name] = temp;
            } else {
                res[name].push_back(index);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> name;
        sort(res[name].begin(), res[name].end());
        cout << name << " " << res[name].size();
        if (res[name].size() != 0) {
            cout << " ";
        }
        for (int j = 0; j < res[name].size(); j++) {
            cout << res[name][j];
            if (j != res[name].size()-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}