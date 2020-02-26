#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
    int id;
    int Ge;
    int Gi;
    int rank;
    double final_grade;
    int choice[5];
}Person;

bool Cmp(Person A, Person B) {
    if (A.final_grade != B.final_grade) {
        return A.final_grade > B.final_grade;
    } else {
        return A.Ge > B.Ge;
    }
}

int main() {
    int N, M, K, id;
    cin >> N >> M >> K;
    int quota[M];
    for (int i = 0; i < M; i++) {
        cin >> quota[i];
    }
    Person p[N];
    for (int i = 0; i < N; i++) {
        p[i].id = i;
        cin >> p[i].Ge >> p[i].Gi;
        for (int j = 0; j < K; j++) {
            cin >> p[i].choice[j];
        }
        p[i].final_grade = (p[i].Ge + p[i].Gi) / 2.0;
    }
    sort(p, p+N, Cmp);
    p[0].rank = 1;
    for (int i = 1; i < N; i++) {
        if (p[i].final_grade != p[i-1].final_grade) {
            p[i].rank = i+1;
        } else if (p[i].final_grade == p[i-1].final_grade && p[i].Ge != p[i-1].Ge) {
            p[i].rank = i+1;
        } else if (p[i].final_grade == p[i-1].final_grade && p[i].Ge == p[i-1].Ge) {
            p[i].rank = p[i-1].rank;
        }
    }
    vector<int> *admit = new vector<int>[M];
    int pre_rank[M];
    for (int i = 0; i < M; i++) {
        pre_rank[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int school_id = p[i].choice[j];
            if (quota[school_id] > 0) {
                quota[school_id]--;
                pre_rank[school_id] = p[i].rank;
                admit[school_id].push_back(p[i].id);
                break;
            } else {
                if (p[i].rank == pre_rank[school_id]) {
                    admit[school_id].push_back(p[i].id);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        sort(admit[i].begin(), admit[i].end());
    }
    for (int i = 0; i < M; i++) {
        int size = admit[i].size();
        for (int j = 0; j < size; j++) {
            cout << admit[i][j];
            if (j != size-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}