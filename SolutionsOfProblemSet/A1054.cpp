/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-24 23:44:36
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 00:00:26
 */

#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int, int> cnt;
int main() {
    int M, N, temp;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &temp);
            if (cnt.find(temp) == cnt.end()) {
                cnt[temp] = 1;
            } else {
                cnt[temp]++;
            }
        }
    }
    unordered_map<int, int> :: iterator iter;
    int max = -1, maxColor;
    iter = cnt.begin();
    while (iter != cnt.end()) {
        if (iter -> second > max) {
            max = iter -> second;
            maxColor = iter -> first;
        }
        iter++;
    }
    printf("%d", maxColor);
    return 0;
}