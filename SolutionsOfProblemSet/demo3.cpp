#include <iostream>
using namespace std;
int upper_bound(int A[], int left, int right, int x) {
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (A[mid] > x) right = mid;
        else left = mid + 1;
    }
    return left;
}
int main() {
    int a[5] = {1, 2, 2, 2, 6};
    cout << upper_bound(a, 0, 4, 6);
    return 0;
}