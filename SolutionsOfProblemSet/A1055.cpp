#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef struct {
    string name;
    int age;
    int worth;
}Person;

bool Cmp(Person A, Person B) {
    if (A.worth != B.worth) {
        return A.worth > B.worth;
    } else if (A.age != B.age) {
        return A.age < B.age;
    } else {
        return A.name < B.name;
    }
}

int main() {
    int N, K;
    vector<string> res;
    scanf("%d%d", &N, &K);
    Person p[N];
    for (int i = 0; i < N; i++) {
        cin >> p[i].name >> p[i].age >> p[i].worth;
    }
    sort(p, p + N, Cmp);
    for (int i = 0; i < K; i++) {
        int cnt, amin, amax;
        bool none = true;
        res.push_back("Case #" + to_string(i+1) + ":");
        scanf("%d%d%d", &cnt, &amin, &amax);
        for (int j = 0; j < N && cnt > 0; j++) {
            if (p[j].age >= amin && p[j].age <= amax) {
                none = false;
                res.push_back(p[j].name + " " + to_string(p[j].age) + " " + to_string(p[j].worth));
                cnt--;
            }
        }
        if (none) {
            res.push_back("None");
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}