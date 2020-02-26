#include <iostream>
using namespace std;
int main() {
    int N, offset;
    cin >> N >> offset;
    offset = offset % N;
    int *arr = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = N-offset; i < N; i++) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < N-offset; i++) {
        cout << arr[i];
        if (i != N-offset-1) {
            cout << " ";
        }
    }
    return 0;
}