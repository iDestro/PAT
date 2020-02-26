#include <iostream>
#include <string>
using namespace std;
typedef struct {
    string name;
    string subject;
    int score;
}Student;
int main() {
    int N;
    cin >> N;
    Student *stu = new Student[N];
    for (int i = 0; i < N; i++) {
        cin >> stu[i].name >> stu[i].subject >> stu[i].score;
    }
    int max_idx = 0, min_idx = 0;
    for (int i = 1; i < N; i++) {
        if (stu[i].score > stu[max_idx].score) max_idx = i;
        if (stu[i].score < stu[min_idx].score) min_idx = i;
    }
    cout << stu[max_idx].name << " " << stu[max_idx].subject << endl;
    cout << stu[min_idx].name << " " << stu[min_idx].subject << endl;
    return 0;
}