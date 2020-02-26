#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef struct {
    string id;
    int time;
    int type;
}Record;

bool Cmp(Record A, Record B) {
    if (A.id != B.id) {
        return A.id < B.id;
    } else {
        return A.time < B.time;
    }
}

bool Cmp1(Record A, Record B) {
    return A.time < B.time;
}

int main() {
    int N, K, hh, mm, ss, maxtime = -1;
    cin >> N >> K;
    string type;
    Record r[N];
    for (int i = 0; i < N; i++)  {
        cin >> r[i].id;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        r[i].time = hh*3600 + mm*60 + ss;
        cin >> type;
        r[i].type = type == "in" ? 1 : -1;
    }
    sort(r, r+N, Cmp);
    
    // 筛数据
    map<string, int> mp;
    vector<Record> valid_r;
    for (int i = 0; i < N; i++)  {
        if (r[i].id == r[i+1].id && r[i].type == 1 && r[i+1].type == -1) {
            valid_r.push_back(r[i]);
            valid_r.push_back(r[i+1]);
            mp[r[i].id] += r[i+1].time - r[i].time;
            if (mp[r[i].id] > maxtime) {
                maxtime = mp[r[i].id];
            }
        }
    }
    
    vector<int> res(valid_r.size());
    

    sort(valid_r.begin(), valid_r.end(), Cmp1);
    res[0] += valid_r[0].type;
    for (int i = 1; i < valid_r.size(); i++) {
        res[i] = res[i-1] + valid_r[i].type;
    }
    int tempindex = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh*3600 + mm*60 + ss;
        int cnt = 0;
        int j;
        for (j = tempindex; j < valid_r.size(); j++) {
            if (valid_r[j].time > time) {
                cout << res[j-1] << endl;
                break;
            } else if (j == valid_r.size()-1) {
                cout << res[j] << endl;
            }
        }
        tempindex = j;
    }
    map<string, int> :: iterator iter;
    iter = mp.begin();
    while (iter != mp.end()) {
        if (iter -> second == maxtime) {
            cout << iter -> first << " ";
        }
        iter++;
    }
    printf("%02d:%02d:%02d", maxtime/3600, maxtime%3600/60, maxtime%60);
    return 0;
}