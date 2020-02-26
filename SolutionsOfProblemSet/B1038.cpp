#include <cstdio>
using namespace std;
int main() {
    int hashtable[101] = {0};
    int N, K, grade;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &grade);
        hashtable[grade]++;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &grade);
        printf("%d", hashtable[grade]);
        if (i != K-1) {
            printf(" ");
        }
    }
    return 0;
}