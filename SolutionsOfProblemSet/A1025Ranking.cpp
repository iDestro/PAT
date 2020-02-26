#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    string registration_number;
    int mark;
    int final_rank;
    int location_number;
    int local_rank;
}Person;

bool Cmp(Person A, Person B) {
    if (A.mark != B.mark) return A.mark > B.mark;
    else return A.registration_number.compare(B.registration_number) < 0;
}
int main() {
    int N; // location;
    int K; // testees;
    cin >> N;
    vector<Person> persons;
    for (int i = 0; i < N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            Person p;
            cin >> p.registration_number >> p.mark;
            p.location_number = i+1;
            persons.push_back(p);
        }
    }
    sort(persons.begin(), persons.end(), Cmp);

    int* pre_mark = new int[N];
    int* pre_rank = new int[N];
    int* count = new int[N];
    fill(pre_mark, pre_mark+N, 0);
    fill(count, count+N, 0);
    fill(pre_rank, count+N, 0);
    for (int i = 0; i < persons.size(); i++) {
        // 对所有对人
        if (i == 0) {
            persons[i].final_rank = 1;
        } else if (persons[i].mark != persons[i-1].mark) {
            persons[i].final_rank = i+1;
        } else {
            persons[i].final_rank = persons[i-1].final_rank;
        }
        
        if (count[persons[i].location_number-1] == 0) {
            persons[i].local_rank = 1;
            pre_rank[persons[i].location_number-1] = 1;
            count[persons[i].location_number-1] = 1;
            pre_mark[persons[i].location_number-1] = persons[i].mark;
        } else if (persons[i].mark != pre_mark[persons[i].location_number-1]) {
            persons[i].local_rank = count[persons[i].location_number-1]+1;
            pre_rank[persons[i].location_number-1] = persons[i].local_rank;
            pre_mark[persons[i].location_number-1] = persons[i].mark;
            count[persons[i].location_number-1]++;
        } else {
            persons[i].local_rank = pre_rank[persons[i].location_number-1];
            count[persons[i].location_number-1]++;
        }
    }
    cout << persons.size() << endl;
    for (int i = 0; i < persons.size(); i++) {
        cout << persons[i].registration_number << " " << persons[i].final_rank << " " << persons[i].location_number << " " << persons[i].local_rank << endl;
    }
    return 0;
}