/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-14 22:40:00
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-14 23:16:34
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstdio>
using namespace std;
//Rank School TWS Ns

struct campus{
    int rank;
    string school;
    double tws;
    double a, b, t;
    int ns;
};



unordered_map<string, campus> temp;
vector<campus> ans;

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool cmp(campus a, campus b) {
    if (a.tws != b.tws) {
        return a.tws > b.tws;
    } else if (a.ns != b.ns) {
        return a.ns < b.ns;
    } else {
        return a.school < b.school;
    }
}

int main() {
    int n;
    double grade;
    cin >> n;
    string id, school;
    for (int i = 0; i < n; i++) {
        cin >> id >> grade >> school;
        school = toLower(school);
        temp[school].school = school;
        if (id[0] == 'A') {
            temp[school].a += grade;
        } else if (id[0] == 'B') {
            temp[school].b += grade;
        } else if (id[0] == 'T') {
            temp[school].t += grade;
        }
        temp[school].ns++;
    }
    unordered_map<string, campus> :: iterator it;
    it = temp.begin();
    while (it != temp.end()) {
        ans.push_back(it -> second);
        it++;
    }
    //ScoreB/1.5 + ScoreA + ScoreT*1.5
    for (int i = 0; i < ans.size(); i++) {
        ans[i].tws = ans[i].b/1.5 + ans[i].a + ans[i].t*1.5;
    }
    sort(ans.begin(), ans.end(), cmp);
    if (ans.size() > 0) {
        ans[0].rank = 1;
    }
    for (int i = 1; i < ans.size(); i++) {
        if ((int)ans[i].tws != (int)ans[i-1].tws) {
            ans[i].rank = i+1;
        } else {
            ans[i].rank = ans[i-1].rank;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %s %d %d\n", ans[i].rank, ans[i].school.c_str(), (int)ans[i].tws, ans[i].ns);
    }
    return 0;
}