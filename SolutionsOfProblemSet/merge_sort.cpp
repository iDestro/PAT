#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;

void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2, index = 0, temp[maxn];
    while (i <= R1 && j <= R2) {
        if (A[i] >= A[j]) {
            temp[index++] = A[j];
        } else {
            temp[index++] = A[i];
        }
    }
    while (i <= R1) {
        temp[index++] = A[i];
    }
    while (j <= R2) {
        temp[index++] = A[j];
    }
    for (int i = 0; i < index; i++) {
        A[L1+i] = temp[i];
    }
}

void merge_sort_recursion(int A[], int left, int right) {
    int mid = left + (right - left) / 2;
    merge_sort_recursion(A, left, mid);
    merge_sort_recursion(A, mid+1, right);
    merge(A, left, mid, mid+1, right);
}

void merge_sort_iteration(int A[], int n) {
    for (int step = 2; step / 2 <= n; step*=2) {
        for (int i = 1; i <= n; i+=step) {
            int mid = i+step/2-1;
            if (mid + 1 <= n) {
                merge(A, i, mid, mid+1, min(i+step-1, n));
            }
        }
    }
}

void merge_sort_print(int A[], int n) {
    for (int step = 2; step/2 <= n; step*=2) {
        for (int i = 1; i <= n; i++) {
            sort(A+i, A + min(i + step, n+1));
        }
    }
}

int main() {

    return 0;
}