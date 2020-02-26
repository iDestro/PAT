/*
 * @Descripttion: 1047 Student List for Course (25/25 分),liucuo手法好，多用空间，换时间，少用scanf
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-22 23:42:49
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-22 23:59:48
 */

#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
vector<int> course[2505];
char names[40005][5];

bool cmp(int a, int b) {
    return strcmp(names[a], names[b]) < 0;
}

int main() {
    int N, K, index, num;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%s %d", names[i], &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &index);
            course[index].push_back(i);
        }
    }
    for (int i = 1; i <= K; i++) {
        printf("%d %ld\n", i, course[i].size());
        if (course[i].size() > 0) {
            sort(course[i].begin(), course[i].end(), cmp);
            for (int j = 0; j < course[i].size(); j++) {
                printf("%s\n", names[course[i][j]]);
            }
        }
    }
}