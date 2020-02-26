#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    string id;
    int virtue_grade;
    int talent_grade;
    int sum;
    int type;
}Person;

int L, H;
bool Cmp(Person A, Person B) {
    if (A.type != B.type) {
        return A.type > B.type;
    } else if (A.sum != B.sum) {
        return A.sum > B.sum;
    } else if (A.virtue_grade != B.virtue_grade) {
        return A.virtue_grade > B.virtue_grade;
    } else {
        return A.id < B.id;
    }
}

int main() {
    int N, cnt;
    cin >> N >> L >> H;
    cnt = N;
    Person *persons = new Person[N];
    for (int i = 0; i < N; i++) {
        cin >> persons[i].id;
        cin >> persons[i].virtue_grade;
        cin >> persons[i].talent_grade;
        persons[i].sum = persons[i].virtue_grade + persons[i].talent_grade;
        if (persons[i].virtue_grade < L || persons[i].talent_grade < L) {
            persons[i].type = -1;
            cnt--;
        } else if (persons[i].virtue_grade >= H && persons[i].talent_grade >= H) {
            persons[i].type = 3;
        } else if (persons[i].virtue_grade >= H && persons[i].talent_grade < H) {
            persons[i].type = 2;
        } else if (persons[i].virtue_grade < H && persons[i].talent_grade < H && persons[i].virtue_grade >= persons[i].talent_grade) {
            persons[i].type = 1;
        } else {
            persons[i].type = 0;
        }
    }
    sort(persons, persons+N, Cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << persons[i].id << " " << persons[i].virtue_grade << " " << persons[i].talent_grade << endl;
    }
    return 0;
}