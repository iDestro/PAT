#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int randPartition(int A[], int left, int right) {
    int p = (int)round(1.0*rand()/RAND_MAX*(right-left) + left);
    swap(A[left], A[p]);
    int temp = A[left];
    while (left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void rand_select(int A[], int left, int right, int K) {
    if (left == right) return;
    int p = randPartition(A, left, right);
    int M = p - left + 1;
    if (M == K) return;
    if (M > K) {
        return rand_select(A, left, p-1, K);
    } else {
        return rand_select(A, p+1, right, K-M);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int sum = 0, sum1 = 0, n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    rand_select(A, 0, n-1, n/2);
    for (int i = 0; i < n/2; i++) {
        sum1 += A[i];
    }
    cout << (sum - sum1) - sum1 << endl;
    return 0;
}