/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-13 23:09:49
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-13 23:40:27
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

struct S {
    string name;
    double gp, gm, gf, g;
    S() {
        this -> gp = this -> gm = this -> gf = -1;
    }
};

unordered_map<string, S> mp;
vector<S> stus;

bool cmp(S a, S b) {
    if ((int)a.g != (int)b.g) {
        return (int)a.g > (int)b.g;
    } else {
        return a.name < b.name;
    }
}

int main() {
    int p, m, n;
    string id;
    cin >> p >> m >> n;
    for (int i = 0; i < p; i++) {
        cin >> id;
        mp[id].name = id;
        cin >> mp[id].gp;
    }
    for (int i = 0; i < m; i++) {
        cin >> id;
        mp[id].name = id;
        cin >> mp[id].gm;
    }
    for (int i = 0; i < n; i++) {
        cin >> id;
        mp[id].name = id;
        cin >> mp[id].gf;
    }
    unordered_map<string, S> :: iterator it;
    it = mp.begin();
    while (it != mp.end()) {
        if (it -> second.gm > it -> second.gf) {
            it -> second.g = it -> second.gm *0.4 + it -> second.gf*0.6 + 0.5;
        } else {
            it -> second.g = it -> second.gf;
        }
        if (it -> second.gp >= 200 && it -> second.g >= 60) {
            stus.push_back(it -> second);
        }
        it++;
    }
    sort(stus.begin(), stus.end(), cmp);
    for (int i = 0; i < stus.size(); i++) {
        printf("%s %d %d %d %d\n", stus[i].name.c_str(), (int)stus[i].gp, (int)stus[i].gm, (int)stus[i].gf, (int)stus[i].g);
    }
    return 0;
}