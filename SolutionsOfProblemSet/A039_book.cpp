#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#define M 26*26*26*10+1
using namespace std;

vector<int> selectCourse[M];
int getID(char *name) {
    int id;
    for (int i = 0; i < 3; i++) {
        id = id*26 + name[i]-'A';
    }
    id += id*10 + name[3]-'0';
    return id;
}

int main() {
    char name[5];
    int N, K, course, num, id;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &course, &num);
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        id = getID(name);
        printf("%s %ld", name, selectCourse[id].size());
        if (selectCourse[id].size() > 0) {
            sort(selectCourse[id].begin(), selectCourse[id].end());
            for (int j = 0; j < selectCourse[id].size(); j++) {
                printf("%d", selectCourse[id][j]);
            }
        }
        printf("\n");
    }
}



