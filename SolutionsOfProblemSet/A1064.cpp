/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 22:45:27
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-25 23:40:00
 */

#include <cstdio>
#include <iostream>
using namespace std;
int *number, *CBT, N, idx = 1;

void inOrder(int root) {
    if (root > N) return;
    inOrder(2*root);
    CBT[root] = number[idx++];
    inOrder(2*root+1);
}

int main() {
    cin >> N;
    number = new int[N+1];
    CBT = new int[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> number[i];
    }
    sort(number+1, number+N+1);
    inOrder(1);
    for (int i = 1; i <= N-1; i++) {
        cout << CBT[i] << " ";
    }
    cout << CBT[N];
    return 0;
}