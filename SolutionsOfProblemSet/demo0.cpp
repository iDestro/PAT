#include <iostream>
using namespace std;
int binary_search(int A[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == x) return mid;
        else if (A[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
int main() {
    int a[10] = {0, 2, 67, 89, 90, 100, 999, 1000, 1050, 2000};
    cout << binary_search(a, 0, 9, 2000);
    return 0;
}