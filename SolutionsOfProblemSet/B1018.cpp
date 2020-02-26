#include <cstdio>
#include <map>
using namespace std;

int main() {
    map<char, int>trans;
    trans['B'] = 0;
    trans['C'] = 1;
    trans['J'] = 2;
    char mp[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);
    int times_A[3] = {0}, times_B[3] = {0};
    int hand_A[3] = {0}, hand_B[3] = {0};
    char c1, c2;
    int k1, k2;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &c1, &c2);
        k1 = trans[c1];
        k2 = trans[c2];
        if ((k1+1) % 3 == k2) {
            times_A[0]++;
            times_B[2]++;
            hand_A[k1]++;
        } else if (k1 == k2) {
            times_A[1]++;
            times_B[1]++;
        } else {
            times_A[2]++;
            times_B[0]++;
            hand_B[k2]++;
        }
    }
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++) {
        if (hand_A[i] > hand_A[id1]) id1 = i;
        if (hand_B[i] > hand_B[id2]) id2 = i;
    }
    printf("%c %c", mp[id1], mp[id2]);
    return 0;
}