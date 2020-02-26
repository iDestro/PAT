#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int N;
    bool flag = true;
    scanf("%d", &N);
    int hashtable[10001] = {0};
    int numbers[100001] = {0};
    for (int i = 0; i < N; i++) {
        int number;
        scanf("%d", &numbers[i]);
        hashtable[numbers[i]]++;
    }

    for (int i = 0; i < N; i++) {
        if (hashtable[numbers[i]] == 1) {
            flag = false;
            printf("%d", numbers[i]);
            break;
        }
    }
    if (flag) {
        printf("None");
    }
}