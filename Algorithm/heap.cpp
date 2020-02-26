#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
int heap[maxn], n = 10;

void downAdjust(int low, int high) {
    int i = low, j = i*2;
    while (j <= high) {
        if (j+1 <= high && heap[j+1] > heap[j]) {
            j = j+1;
        }
        if (heap[i] > heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
}


void create() {
    for (int i = n/2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

void upAdjust(int low, int high) {
    int i = high, j = i/2;
    while (i >= low) {
        if (heap[i] > heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i/2;
        } else {
            break;
        }
    }
}

void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort() {
    create();
    for (int i = n; i > 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i-1);
    }
}

int main() {
    return 0;
}