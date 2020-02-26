#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int K, cnt = 0;
    bool hashtable[101] = {false};
    cin >> K;
    int nums[K];
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
        hashtable[nums[i]] = true;
    }
    sort(nums, nums+K);
    for (int i = 0; i < K; i++) {
        int temp = nums[i];
        if (hashtable[temp] == true)
        while (temp != 1) {
            if (temp % 2 == 1) {
                temp = (3*temp+1)/2;
            } else {
                temp /= 2;
            }
            if (temp <= 100) {
                if (hashtable[temp] == true) {
                cnt++;
            }
                hashtable[temp] = false;
            }
        }
    }
    cnt = K-cnt;
    for (int i = 100; i > 0; i--) {
        if (hashtable[i] == true) {
            cnt--;
            printf("%d", i);
            if (cnt != 0) {
                printf(" ");
            }
        }
    }
}