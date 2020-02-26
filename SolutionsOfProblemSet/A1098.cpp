#include <iostream>
#include <algorithm>
using namespace std;


int A[101], pA[101], N, tempA[101];


bool judge(int A[]) {
    for (int i = 1; i <= N; i++) {
        if (A[i] != pA[i]) {
            return false;
        }
    }
    return true;
}

void disp(int A[]) {
    for (int i = 1; i <= N; i++) {
        cout << A[i];
        if (i != N) {
            cout << " ";
        }
    }
}

bool InsertionSort() {
    for (int i = 2; i <= N; i++) {
        sort(A+1,A+1+i);
        if (judge(A)) {
            cout << "Insertion Sort" << endl;
            sort(A+1,A+2+i);
            disp(A);
            return true;
        }
    }
    return false;
}

void downAdjust(int low, int high) {
    int i = low, j = 2*i;
    while (j <= high) {
        if (j+1 <= high && tempA[j+1] > tempA[j]) {
            j = j+1;
        }
        if (tempA[j] > tempA[i]) {
            swap(tempA[j], tempA[i]);
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
}

void HeapSort() {
    for (int i = N/2; i >= 1; i--) {
        downAdjust(i, N);
    }
    for (int i = N; i > 1; i--) {
        swap(tempA[1], tempA[i]);
        downAdjust(1, i-1);
        if (judge(tempA)) {
            cout << "Heap Sort" << endl;
            swap(tempA[1], tempA[i-1]);
            downAdjust(1, i-2);
            disp(tempA);
            break;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        tempA[i] = A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> pA[i];
    }
    if (!InsertionSort()) {
        HeapSort();
    }
    return 0;
}