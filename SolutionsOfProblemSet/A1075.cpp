#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct {
    int id;
    int grade[5];
    int total;
    int rank;
    int solved[5];
    int solved_num;
    int issub;
}Person;

bool Cmp(Person A, Person B) {
    if (A.total != B.total) {
        return A.total > B.total;
    } else if (A.solved_num != B.solved_num) {
        return A.solved_num > B.solved_num;
    } else {
        return A.id < B.id;
    }
}
int N, K, M;

int main() {
    cin >> N >> K >> M;
    Person persons[N+1];
    int idx[5];
    // 成绩
    for (int i = 0; i < K; i++) {
        cin >> idx[i];
    }
    // 初始化
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < 5; j++) {
            persons[i].grade[j] = -2;
            persons[i].solved[j] = 0;
        }
        persons[i].total = 0;
        persons[i].solved_num = 0;
        persons[i].issub = 0;
    }

    // 输入数据
    for (int i = 0; i < M; i++) {
        int id, p, m;
        cin >> id >> p >> m;
        persons[id].id = id;
        persons[id].grade[p-1] = max(m, persons[id].grade[p-1]);
        if (m != -1) {
            persons[id].issub = 1;
            if (m == idx[p-1]) {
                persons[id].solved[p-1] = 1;
            }
        }
    }
    // 计算总和，通过数量
    for (int i = 1; i < N+1; i++) {
        for (int j = 0; j < K; j++) {
            if (persons[i].grade[j] != -2 && persons[i].grade[j] != -1) {
                persons[i].total += persons[i].grade[j];
            }
            persons[i].solved_num += persons[i].solved[j];
        }
    }

    // 按规则进行排序
    sort(persons+1, persons + N+1, Cmp);
    // 计算排名
    persons[1].rank = 1;
    for (int i = 2; i < N+1; i++) {
        if (persons[i].total != persons[i-1].total) {
            persons[i].rank = i;
        } else {
            persons[i].rank = persons[i-1].rank;
        }
    }
    // 按格式进行输出
    for (int i = 1; i < N+1; i++) {
        if (persons[i].issub) {
            printf("%d %05d %d ", persons[i].rank, persons[i].id, persons[i].total);
            for (int j = 0; j < K; j++) {
                if (persons[i].grade[j] != -2 && persons[i].grade[j] != -1) {
                    printf("%d", persons[i].grade[j]);
                } else if (persons[i].grade[j] == -2){
                    printf("-");
                } else if (persons[i].grade[j] == -1){
                    printf("0");
                }
                if (j != K-1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

