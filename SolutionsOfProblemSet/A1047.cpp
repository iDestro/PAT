/*
 * @Descripttion: 1047 Student List for Course (18/25 分),超时和答案错
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-22 23:21:00
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-22 23:42:36
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    int n, index;
    cin >> N >> K;
    string name;
    map<int, vector<string> > res;
    for (int i = 0; i < N; i++) {
        cin >> name >> n;
        for (int j = 0; j < n; j++) {
            cin >> index;
            if (res.find(index) == res.end()) {
                vector<string> temp;
                temp.push_back(name);
                res[index] = temp;
            } else {
                res[index].push_back(name);
            }
        }
    }
    map<int, vector<string> > :: iterator iter;
    iter = res.begin();
    while (iter != res.end()) {
        sort(iter->second.begin(), iter->second.end());
        cout << iter->first << " " << iter->second.size() << endl;
        for (int i = 0; i < iter->second.size(); i++) {
            cout << iter->second[i] <<endl;
        }
        iter++;
    }
    return 0;
}