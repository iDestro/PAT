#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
    string name;
    string id;
    int grade;
}Person;

bool Cmp(Person A, Person B) {
    return A.grade > B.grade;
}

int main() {
    int N, g1, g2, cnt = 0;
    cin >> N;
    Person p[N];
    for (int i = 0; i < N; i++) {
        cin >> p[i].name >> p[i].id >> p[i].grade;
    }
    cin >>  g1 >> g2;
    sort(p, p + N, Cmp);
    for (int i = 0; i < N; i++) {
        if (p[i].grade >= g1 && p[i].grade <= g2) {
            cnt++;
            cout << p[i].name << " " << p[i].id << endl;
        }
    }
    if (cnt == 0) {
        cout << "NONE";
    }
    return 0;
}