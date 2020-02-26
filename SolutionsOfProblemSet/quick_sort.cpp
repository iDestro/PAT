#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;


int partition(int A[], int left, int right)  {
    int temp = A[left];
    while (left < right) {
        while (A[right] > temp && left < right) right--;
        A[left] = A[right];
        while (A[left] < temp && left < right) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quick_sort(int A[], int left, int right) {
    if (left < right) {
        int pos = partition(A, left, right);
        quick_sort(A, left, pos-1);
        quick_sort(A, pos+1, right);
    }
}

int rand_partition(int A[], int left, int right) {
    int p = (int)round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(A[p], A[left]);
    int temp = A[left];
    while (left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] < temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

int main() {
    srand((unsigned)time(NULL));
    return 0;
}