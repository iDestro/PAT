/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-08 21:50:26
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-08 21:56:50
 */
#include <iostream>
using namespace std;

int Partition(int A[], int left, int right) {
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

void quicksort(int A[], int left, int right) {
    if (left < right) {
        int pos = Partition(A, left, right);
        quicksort(A, left,  pos-1);
        quicksort(A, pos+1, right);
    }
}

int main() {
    int A[6] = {4, 3, 2, 6, 99, 100};
    quicksort(A, 0, 5);
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }
    return 0;
}