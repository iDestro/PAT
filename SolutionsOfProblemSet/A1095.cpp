#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
typedef struct {
    string id;
    int time[3];
    int type;
    int total_time;
}Record;

typedef struct {
    string id;
    int time_cost;
}TimeCost;

bool Cmp_cost(TimeCost A, TimeCost B) {
    if (A.time_cost != B.time_cost) {
        return A.time_cost > B.time_cost;
    } else {
        return A.id < B.id;
    }
}

bool Cmp(Record A, Record B) {
    if (A.id != B.id) {
        return A.id > B.id;
    } else if (A.time[0] != B.time[0]) {
        return A.time[0] < B.time[0];
    } else if (A.time[1] != B.time[1]) {
        return A.time[1] < B.time[1];
    } else {
        return A.time[2] < B.time[2];
    }
}

bool Cmp_time(Record A, Record B) {
    return A.total_time < B.total_time;
}

int main() {
    int N, K;
    cin >> N >> K;
    Record r[N];
    string type;
    for (int i = 0; i < N; i++) {
        cin >> r[i].id;
        scanf("%d:%d:%d", &r[i].time[0], &r[i].time[1], &r[i].time[2]);
        cin >> type;
        r[i].type = type == "in" ? 1 : 0;
        r[i].total_time = r[i].time[0]*3600 + r[i].time[1]*60 + r[i].time[2];
    }
    sort(r, r+N, Cmp);

    // cout << "总数据" << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << r[i].id << " ";
    //     printf("%d:%d:%d ", r[i].time[0], r[i].time[1], r[i].time[2]);
    //     if (r[i].type == 1) {
    //         cout << "in";
    //     } else {
    //         cout << "out";
    //     }
    //     cout << endl;
    // }

    // 清洗数据
    stack<Record> S;
    vector<Record> r_new;
    for (int i = 0; i < N; i++) {
        if (S.empty()) {
            if (r[i].type == 1) {
                S.push(r[i]);
            }
        } else {
            Record t = S.top();
            if (t.id == r[i].id) {
                if (t.type == 1 && r[i].type == 0) {
                    r_new.push_back(t);
                    r_new.push_back(r[i]);
                    S.pop();
                } else if (t.type == 1 && r[i].type == 1) {
                    S.pop();
                    S.push(r[i]);
                }
            }
        }
        
    }

    // 清洗的数据
    // cout << "清洗的数据" << endl;
    // for (int i = 0; i < r_new.size(); i++) {
    //     cout << r_new[i].id << " ";
    //     printf("%d:%d:%d ", r_new[i].time[0], r_new[i].time[1], r_new[i].time[2]);
    //     if (r_new[i].type == 1) {
    //         cout << "in";
    //     } else {
    //         cout << "out";
    //     }
    //     cout << endl;
    // }
    map<string, int> park_time;
    for (int i = 0; i < r_new.size(); i++) {
        park_time[r_new[i].id] = 0;
    }
    for (int i = 0; i < r_new.size(); i+=2) {
        int cost = r_new[i+1].total_time - r_new[i].total_time;
        park_time[r_new[i].id] += cost;
    }

    vector<TimeCost> tc_list;
    map<string, int> :: iterator it;
    it = park_time.begin();
    while (it != park_time.end()) {
        TimeCost tc;
        tc.id = it -> first;
        tc.time_cost = it -> second;
        tc_list.push_back(tc);
        it++;
    }
    sort(tc_list.begin(), tc_list.end(), Cmp_cost);
    // 输出花费时间
    // cout << "输出花费时间" << endl;
    // it = park_time.begin();
    // while (it != park_time.end()) {
    //     int hh = it -> second / 3600;
    //     int mm = it -> second % 3600 / 60;
    //     int ss = it -> second % 60;
    //     cout << it -> first << " ";
    //     printf("%d:%d:%d\n", hh, mm, ss);
    //     it++;
    // }

    sort(r_new.begin(), r_new.end(), Cmp_time);
    for (int i = 0; i < K; i++) {
        int hh, mm, ss, total, cnt = 0;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        total = hh*3600 + mm*60 + ss;
        int j = 0;
        for (; j < r_new.size(); j++) {
            if (r_new[j].total_time > total) {
                break;
            }
        }
        for (int k = 0; k < j; k++) {
            if (r_new[k].type == 1) {
                cnt++;
            } else {
                cnt--;
            }
        }
        cout << cnt << endl;
    }
    cout << tc_list[0].id << " ";
    for (int i = 1; i < tc_list.size(); i++) {
        if (tc_list[i].time_cost == tc_list[i-1].time_cost) {
            cout << tc_list[i].id << " ";
        }
    }
    printf("%02d:%02d:%02d\n", tc_list[0].time_cost/3600, tc_list[0].time_cost%3600/60, tc_list[0].time_cost%60);
    return 0;
}