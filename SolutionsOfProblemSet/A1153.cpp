/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-17 23:08:19
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-18 00:26:18
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct P {
    string id;
    int grade;
};

struct PPP {
    string ns;
    int n;
    PPP(string s, int nn) {
        this -> ns = s;
        this -> n = nn;
    }
};

int type;
string flag;
int level_cnt[256] = {0}, ns_cnt[1000] = {0}, ns_cnt_0[1000] = {0};


bool cmp0(P a, P b) {
    if (a.id[0] == flag[0] && b.id[0] != flag[0]) {
        return true;
    } else if (a.id[0] == flag[0] && b.id[0] == flag[0]) {
        if (a.grade != b.grade) {
            return a.grade > b.grade;
        } else {
            return a.id < b.id;
        }
    } else {
        return false;
    }
}

bool cmp1(PPP a, PPP b) {
    if (ns_cnt_0[stoi(a.ns)] != ns_cnt_0[stoi(b.ns)]) {
        return ns_cnt_0[stoi(a.ns)] > ns_cnt_0[stoi(b.ns)];
    } else {
        return a.ns < b.ns;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    P p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].grade;
        level_cnt[p[i].id[0]]++;
        ns_cnt[stoi(p[i].id.substr(1, 3))]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> type >> flag;
        if (type == 1) {
            sort(p, p+n, cmp0);
            printf("Case %d: %d %c\n", i+1, type, flag[0]);
            if (level_cnt[flag[0]] == 0) {
                printf("NA\n");
            } else {
                for (int j = 0; j < level_cnt[flag[0]]; j++) {
                    cout << p[j].id << " " << p[j].grade << endl;
                }
            }
            
        } else if (type == 2) {
            int sum = 0, ccc = 0;
            for (int j = 0; j < n; j++) {
                if (p[j].id.substr(1, 3) == flag) {
                    sum += p[j].grade;
                    ccc++;
                }
            }
            printf("Case %d: %d %s\n", i+1, type, flag.c_str());
            if (ccc == 0) {
                printf("NA\n");
            } else {
                printf("%d %d\n", ns_cnt[stoi(flag)], sum);
            }
        } else if (type == 3) {
            vector<PPP> ttt;
            for (int j = 0; j < n; j++) {
                if (p[j].id.substr(4, 6) == flag) {
                    ns_cnt_0[stoi(p[j].id.substr(1, 3))]++;
                }
            }
            for (int j = 0; j < n; j++) {
                bool fff = true;
                if (p[j].id.substr(4, 6) == flag) {
                    for (int k = 0; k < ttt.size(); k++) {
                        if (ttt[k].ns == p[j].id.substr(1, 3)) {
                            fff = false;
                        }
                    }
                    if (fff) {
                        ttt.push_back(PPP(p[j].id.substr(1, 3), ns_cnt_0[stoi(p[j].id.substr(1, 3))]));
                    }
                }
            }
            if (ttt.size() == 0) {
                printf("NA\n");
            } else {
                sort(ttt.begin(), ttt.end(), cmp1);
                printf("Case %d: %d %s\n", i+1, type, flag.c_str());
                for (int j = 0; j < ttt.size(); j++) {
                    cout << ttt[j].ns << " " << ttt[j].n << endl;
                }
            }
        }
    }
    return 0;
}