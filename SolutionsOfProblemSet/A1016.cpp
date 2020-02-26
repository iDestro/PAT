#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
typedef struct {
    int time[4];
    string type;
}Record;

bool Cmp(Record A, Record B) {
    if (A.time[0] != B.time[0]) {
        return A.time[0] < B.time[0];
    } else if (A.time[1] != B.time[1]) {
        return A.time[1] < B.time[1];
    } else if (A.time[2] != B.time[2]) {
        return A.time[2] < B.time[2];
    } else {
        return A.time[3] < B.time[3];
    }
}
int w[24] = {0};
int res[2] = {0};
void cal_money(int t1[], int t2[]) {
    int money_sum = 0;
    int cnt = 0;
    while (t1[1] != t2[1] || t1[2] != t2[2] || t1[3] != t2[3]) {
        money_sum += w[t1[2]];
        if (t1[3] == 60) {
            t1[2]++;
            t1[3] = 0;
        }
        if (t1[2] == 24) {
            t1[1]++;
            t1[2] = 0;
        }
        t1[3]++;
        cnt++;
    }
    res[0] = cnt;
    res[1] = money_sum;
}

int main() {
    map<string, vector<Record> > mp;
    string name;
    int N;
    for (int i = 0; i < 24; i++) {
        cin >> w[i];
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name;
        Record r;
        scanf("%d:%d:%d:%d", &r.time[0], &r.time[1], &r.time[2], &r.time[3]);
        cin >> r.type;
        if (mp.find(name) == mp.end()) {
            vector<Record> record_list;
            record_list.push_back(r);
            mp[name] = record_list;
        } else {
            mp[name].push_back(r);
        }
    }

    // 按组进行排序
    map<string, vector<Record> > :: iterator it;
    it = mp.begin();
    while (it != mp.end()) {
        sort(it->second.begin(), it->second.end(), Cmp);
        it++;
    }
    // 分割线
    for (int i = 0; i < 10; i++) {
        cout << "-";
    }
    cout << endl;
    // 删除不合法的数据
    it = mp.begin();
    while (it != mp.end()) {
        vector<Record> :: iterator iter;
        iter = it->second.begin();
        while (iter != it->second.end()) {
            if (iter == it->second.begin() && iter -> type == "off-line") {
                iter = it -> second.erase(iter);
            } else if (iter -> type == (iter+1) -> type) {
                iter = it -> second.erase(iter);
            }
            if (iter == it -> second.end()) {
                break;
            }
            iter++;
        }
        it++;
    }

    // 输出数据
    // it = mp.begin();
    // while (it != mp.end()) {
    //     vector<Record> :: iterator iter;
    //     iter = it->second.begin();
    //     while (iter != it->second.end()) {
    //         cout << it -> first << " ";
    //         for (int i = 0; i < 4; i++) {
    //             cout << iter -> time[i];
    //             if (i != 3) {
    //                 cout << ":";
    //             }
    //         }
    //         cout << " " << iter -> type << endl;
    //         iter++;
    //     }
    //     it++;
    // }
    // 计算并输出
    // 分割线
    for (int i = 0; i < 10; i++) {
        cout << "-";
    }
    cout << endl;
    it = mp.begin();
    while (it != mp.end()) {
        cout << it -> first;
        printf(" %02d\n", it -> second[0].time[0]);
        int i  = 0;
        for (int i = 0; i < it -> second.size(); i+=1) {
            printf("%d:%d:%d ", it->second[i].time[1], it->second[i].time[2], it->second[i].time[3]);
            printf("%d:%d:%d ", it->second[i+1].time[1], it->second[i+1].time[2], it->second[i+1].time[3]);
            cal_money(it->second[i].time, it->second[i+1].time);
            cout << res[0] << " " << res[1] << endl;
        }
        it++;
    }

    // 测试
    // int A[4] = {1, 2, 0, 1};
    // int B[4] = {1, 4, 23, 59};
    // cout << cal_money(A, B) << endl;
    return 0;
}
