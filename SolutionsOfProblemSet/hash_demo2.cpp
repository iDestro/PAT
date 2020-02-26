#include <cstdio>
int hashFunc0(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}

int hashFunc(char S[], int len) {
    int id = 0; 
    for (int i = 0; i < len; i++) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            id = id * 52 + S[i] - 'A';
        } else if (S[i] >= 'a' && S[i] <= 'z') {
            id = id * 52 + S[i] - 'a' + 26;
        }
    }
    return id;
}

int hashFunc2(char S[], int len) {
    int id = 0;
    for (int i = 0; i < len-1; i++) {
        id = id * 26 + S[i] - 'A';
    }
    id = id * 10 + S[len-1] - '0';
    return id;
}
// 给出N个字符串（由恰好三位大写字母组成），再给出M个查询字符串，问每个查询字符在N个字符串出现的次数

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26*26*26+10] = {0};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", S[i]);
        int id = hashFunc0(S[i], 3);
        hashTable[id]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", temp);
        int id = hashFunc0(temp, 3);
        printf("%d\n", hashTable[id]);
    }
    return 0;
}