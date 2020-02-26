#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int hashtable[1001] = {0};
    int N; 
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int team_id, person_id, grade;
        scanf("%d-%d %d", &team_id, &person_id, &grade);
        hashtable[team_id] += grade;
    }
    int max = 1;
    for (int i = 2; i <= 1000; i++) {
        if (hashtable[i] > hashtable[max]) {
            max = i;
        }
    }
    printf("%d %d", max, hashtable[max]);
}