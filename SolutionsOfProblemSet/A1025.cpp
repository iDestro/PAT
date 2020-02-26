#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    string id;
    int loc_num;
    int loc_rank;
    int final_rank;
    int grade;
}Person;

bool Cmp(Person A, Person B) {
    if (A.grade != B.grade) {
        return A.grade > B.grade;
    } else {
        return A.id > B.id;
    }  
}

int main() {
    int N, K, cnt = 0;
    cin >> N;
    vector<Person> persons;
    for (int i = 0; i < N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            Person p;
            cin >> p.id >> p.grade;
            p.loc_num = i+1;
            persons.push_back(p);
        }
        sort(persons.begin()+cnt, persons.end(), Cmp);
        persons[cnt].loc_rank = 1;
        for (int k = cnt+1; k < cnt+K; k++) {
            if (persons[k].grade != persons[k-1].grade) {
                persons[k].loc_rank = k-cnt+1;
            } else {
                persons[k].loc_rank = persons[k-1].loc_rank;
            }
        }
        cnt+=K;
    }
    sort(persons.begin(), persons.end(), Cmp);
    cout << cnt << endl;
    persons[0].final_rank = 1;
    cout << persons[0].id << " " << persons[0].final_rank << " " << persons[0].loc_num << " " << persons[0].loc_rank << endl;
    for (int k = 1; k < cnt; k++) {
        if (persons[k].grade != persons[k-1].grade) {
            persons[k].final_rank = k+1;
        } else {
            persons[k].final_rank = persons[k-1].final_rank;
        }
        cout << persons[k].id << " " << persons[k].final_rank << " " << persons[k].loc_num << " " << persons[k].loc_rank << endl;
    }
    return 0;
}