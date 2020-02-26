#include <iostream>
using namespace std;
int low_bound(int A[], int left, int right, int x) {
    while (left < right) { // 对[left, right]来说，left==right意味着找到唯一位置
        int mid = left + (right - left) / 2;
        if (A[mid] <= x) {
            right = mid;
        } else {
            left = mid + 1;
        }   
    }
    return left;
}
int main() {
    return 0;
}