#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef struct {
    string id;
    double grade[4];
    int rank[4];
    int max_idx;
}Person;

int now;

bool Cmp(Person A, Person B) {
    return A.grade[now] > B.grade[now];
}

int main() {
    int N, M;
    cin >> N >> M;
    string mp = "ACME";
    map<string, int> rank;
    Person *persons = new Person[N];
    for (int i = 0; i < N; i++) {
        cin >> persons[i].id >> persons[i].grade[1] >> persons[i].grade[2] >> persons[i].grade[3];
        persons[i].grade[0] = (persons[i].grade[1] + persons[i].grade[2] + persons[i].grade[3]) / 3.0 + 0.5;
    }
    sort(persons, persons+N, Cmp);
    for (int i = 0; i < 4; i++) {
        now = i;
        sort(persons, persons + N, Cmp);
        persons[0].rank[i] = 1;
        for (int j = 1; j < N; j++) {
            if (persons[j].grade[i] != persons[j-1].grade[i]) {
                persons[j].rank[i] = j + 1;
            } else {
                persons[j].rank[i] = persons[j-1].rank[i];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int max_rank = 0;
        for (int j = 1; j < 4; j++) {
            if (persons[i].rank[j] < persons[i].rank[max_rank]) {
                max_rank = j;
            }
        }
        persons[i].max_idx = max_rank;
    }
    map<string, Person> m;
    for (int i = 0; i < N; i++) {
        m[persons[i].id] = persons[i];
    }
    for (int i = 0; i < M; i++) {
        string id;
        cin >> id;
        if (m.find(id) != m.end()) {
            cout << m[id].rank[m[id].max_idx] << " " << mp[m[id].max_idx] << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}