#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct {
    int id;
    char name[9];
    int grade;
}Record;

int C;

bool Cmp(Record A, Record B) {
    if (C == 1) {
        return A.id < B.id;
    } else if (C == 2) {
        if (strcmp(A.name, B.name) != 0) {
            return strcmp(A.name, B.name) < 0;
        } {
            return A.id < B.id;
        }
    } else {
        if (A.grade != B.grade) {
            return A.grade < B.grade;
        } else {
            return A.id < B.id;
        }
    }
}

int main() {
    int N;
    cin >> N >> C;
    Record records[N];
    for (int i = 0; i < N; i++) {
        scanf("%d%s%d", &records[i].id, records[i].name, &records[i].grade);
    }
    sort(records, records + N, Cmp);
    for (int i = 0; i < N; i++) {
        printf("%06d %s %d\n", records[i].id, records[i].name, records[i].grade);
    }
    return 0;
}